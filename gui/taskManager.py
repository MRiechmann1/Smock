from command import Command
from computerStatus import ComputerStatus
from message import Message
import ctypes
import time


class TaskManager:
    """
    Reads the tasks from the queue_manager and when there are tasks it responds to them and does some stuff, given to
    the situation.
    """
    def __init__(self, user_manager, queue_manager, serial_manager):
        """
        Constructor of the TaskManager.

        Args:
            user_manager: A userManager
            queue_manager: A queueManager
            serial_manager: A serialManager
        """
        self.__user_manager = user_manager
        self.__queue_manager = queue_manager
        self.__serial_manager = serial_manager
        self.__user32 = ctypes.windll.User32
        self.gui = None
        self.LOCK_WINDOW_NAME_GERMAN = "Windows-Standardsperrbildschirm"
        self.LOCK_WINDOW_NAME_ENGLISH = "Windows Default Lock Screen"

    def read_tasks(self):
        """
        Reads from each queue and when it gets a message it handles the message.
        """
        while True:
            time.sleep(0.01)
            message = self.__queue_manager.read_queue(Command.PASSWORD.value)
            if message.get_text() != "nothing":
                # handle password task
                self.send_password_to_controller(message.get_text())
            message = self.__queue_manager.read_queue(Command.COMPUTER_STATUS.value)
            if message.get_text() != "nothing":
                # handle computer status task
                self.__send_computer_status()
            message = self.__queue_manager.read_queue(Command.UID.value)
            if message.get_text() != "nothing":
                # handle uid tasks
                self.__update_add_window(message.get_text())

    def send_password_to_controller(self, uid):
        # TODO: \n to password
        """
        Sends the password of the user with the given uid. Is the computer locked, the method processes.
        When the computer is unlocked, the computer status will be send to the micro controller

        Args:
            uid: The uid from the user with the password
        """
        found_user = False
        if self.__is_locked():
            user = self.__user_manager.get_user_with_uid(uid)
            if user != -1:
                print(user.get_password().encode())
                message = Message(Command.PASSWORD.value, user.get_password().encode())
                self.__serial_manager.write_to_controller(message)
                found_user = True

        if not found_user:
            message = Message(Command.COMPUTER_STATUS.value, ComputerStatus.UNLOCKED.value)
            self.__serial_manager.write_to_controller(message)

    def __send_computer_status(self):
        """
        Sends the computer status of the computer to the micro controller.
        Either locked screen or unlocked.
        """
        if self.__is_locked():
            message = Message(Command.COMPUTER_STATUS.value, ComputerStatus.LOCKED.value)
        else:
            message = Message(Command.COMPUTER_STATUS.value, ComputerStatus.UNLOCKED.value)
        self.__serial_manager.write_to_controller(message)

    def __get_current_process(self):
        """
        Identifying what window is on focus.

        Returns:
             Value of the window title that is on focus
        """
        hwnd = self.__user32.GetForegroundWindow()

        pid = ctypes.c_ulong(0)
        self.__user32.GetWindowThreadProcessId(hwnd, ctypes.byref(pid))

        window_title = ctypes.create_string_buffer(512)
        self.__user32.GetWindowTextA(hwnd, ctypes.byref(window_title), 512)

        return window_title.value.decode('ASCII')

    def __is_locked(self):
        """
        Returning the computer status

        Returns:
             Returns True if computer is locked, otherwise return False
        """
        lock_window_name = self.__get_current_process()

        return lock_window_name == self.LOCK_WINDOW_NAME_ENGLISH or lock_window_name == self.LOCK_WINDOW_NAME_GERMAN

    def __update_add_window(self, uid):
        """
        Updates the uid label, when the user wants to add a new user.

        Args:
            uid: the uid that should be updated
        """
        if self.gui is not None:
            self.gui.update_uid_label(uid)

    def compare_strings(self, first_string, second_string):
        if len(first_string) != len(second_string):
            return False

        for i in range(len(second_string)):
            if first_string[i] != second_string[i]:
                return False
        return True
