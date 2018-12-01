//*****************************************************************************
//
// usb_structs.c - Data structures defining the USB keyboard and mouse device.
//
// Copyright (c) 2009-2015 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
// This is part of revision 2.1.1.71 of the DK-TM4C129X Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "usblib/usblib.h"
#include "usblib/usbhid.h"
#include "usblib/usb-ids.h"
#include "usblib/device/usbdevice.h"
#include "usblib/device/usbdcomp.h"
#include "usblib/device/usbdhid.h"
#include "usblib/device/usbdhidmouse.h"
#include "usblib/device/usbdhidkeyb.h"
#include "usb_structs.h"
#include "usb_keyboard.h"

//*****************************************************************************
//
// Flags for Keyboard and Mouse shared states.
//
//*****************************************************************************
volatile uint32_t g_ui32USBFlags;

//*****************************************************************************
//
// The languages supported by this device.
//
//*****************************************************************************
//TODO: Language anpassen bzw. fuer Tastertur layout optimieren -> ggf, an anderer Stelle schon umrechen
const uint8_t g_pui8LangDescriptor[] =
{
    4,
    USB_DTYPE_STRING,
    USBShort(USB_LANG_EN_US)
};

//*****************************************************************************
//
// The manufacturer string.
//
//*****************************************************************************
const uint8_t g_pui8ManufacturerString[] =
{
    (17 + 1) * 2,
    USB_DTYPE_STRING,
    'T', 0, 'e', 0, 'x', 0, 'a', 0, 's', 0, ' ', 0, 'I', 0, 'n', 0, 's', 0,
    't', 0, 'r', 0, 'u', 0, 'm', 0, 'e', 0, 'n', 0, 't', 0, 's', 0,
};

//*****************************************************************************
//
// The product string.
//
//*****************************************************************************
const uint8_t g_pui8ProductString[] =
{
    (13 + 1) * 2,
    USB_DTYPE_STRING,
    'M', 0, 'o', 0, 'u', 0, 's', 0, 'e', 0, ' ', 0, 'E', 0, 'x', 0, 'a', 0,
    'm', 0, 'p', 0, 'l', 0, 'e', 0
};

//*****************************************************************************
//
// The serial number string.
//
//*****************************************************************************
const uint8_t g_pui8SerialNumberString[] =
{
    (8 + 1) * 2,
    USB_DTYPE_STRING,
    '1', 0, '2', 0, '3', 0, '4', 0, '5', 0, '6', 0, '7', 0, '8', 0
};

//*****************************************************************************
//
// The descriptor string table.
//
//*****************************************************************************
const uint8_t * const g_pui8StringDescriptors[] =
{
    g_pui8LangDescriptor,
    g_pui8ManufacturerString,
    g_pui8ProductString,
    g_pui8SerialNumberString,
};

#define NUM_STRING_DESCRIPTORS (sizeof(g_pui8StringDescriptors) /             \
                                sizeof(uint8_t *))


//*****************************************************************************
//
// The HID keyboard device initialization and customization structures.
//
//*****************************************************************************
tUSBDHIDKeyboardDevice g_sKeyboardDevice =
{
    //
    // Tiva VID.
    //
    USB_VID_TI_1CBE,

    //
    // Tiva HID Mouse PID.
    //
    USB_PID_KEYBOARD,

    //
    // This is in 2mA increments so 500mA.
    //
    250,

    //
    // Bus powered device.
    //
    USB_CONF_ATTR_BUS_PWR,

    //
    // The Keyboard handler function.
    //
    USBKeyboardHandler,

    //
    // Point to the mouse device structure.
    //
    (void *)&g_sKeyboardDevice,

    //
    // The composite device does not use the strings from the class.
    //
    g_pui8StringDescriptors,
    // 0,
    NUM_STRING_DESCRIPTORS
    // 0,
};

