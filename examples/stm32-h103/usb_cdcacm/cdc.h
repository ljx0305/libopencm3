/*
 * This file is part of the libopenstm32 project.
 *
 * Copyright (C) 2010  Gareth McMullin <gareth@blacksphere.co.nz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __CDC_H
#define __CDC_H

/* Definitions of Communications Device Class from
 * "Universal Serial Bus Class Definitions for Communications Devices 
 * Revision 1.2"
 */

/* Table 2: Communications Device Class Code */
#define USB_CLASS_CDC		0x02

/* Table 4: Class Subclass Code */
#define USB_CDC_SUBCLASS_DLCM	0x01
#define USB_CDC_SUBCLASS_ACM	0x02
/* ... */

/* Table 5 Communications Interface Class Control Protocol Codes */
#define USB_CDC_PROTOCOL_NONE	0x00
#define USB_CDC_PROTOCOL_AT	0x01
/* ... */

/* Table 6: Data Interface Class Code */
#define USB_CLASS_DATA		0x0A

/* Table 12: Type Values for the bDescriptorType Field */
#define CS_INTERFACE		0x24
#define CS_ENDPOINT		0x25

/* Table 13: bDescriptor SubType in Communications Class Functional 
 * Descriptors */
#define USB_CDC_TYPE_HEADER	0x00
#define USB_CDC_TYPE_CALL_MANAGEMENT	0x01
#define USB_CDC_TYPE_ACM	0x02
/* ... */
#define USB_CDC_TYPE_UNION	0x06
/* ... */

/* Table 15: Class-Specific Descriptor Header Format */
struct usb_cdc_header_descriptor {
	uint8_t bFunctionLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint16_t bcdCDC;
} __attribute__((packed));

/* Table 16: Union Interface Functional Descriptor */
struct usb_cdc_union_descriptor {
	uint8_t bFunctionLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bControlInterface;
	uint8_t bSubordinateInterface0;
	/* ... */
} __attribute__((packed));


/* Definitions for Abstract Control Model devices from:
 * "Universal Serial Bus Communications Class Subclass Specification for
 * PSTN Devices"
 */

/* Table 3: Call Management Functional Descriptor */
struct usb_cdc_call_management_descriptor {
	uint8_t bFunctionLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bmCapabilities;
	uint8_t bDataInterface;
} __attribute__((packed));

/* Table 4: Abstract Control Management Functional Descriptor */
struct usb_cdc_acm_descriptor {
	uint8_t bFunctionLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bmCapabilities;
} __attribute__((packed));

/* Table 13: Class-Specific Request Codes for PSTN subclasses */
/* ... */
#define USB_CDC_REQ_SET_LINE_CODING		0x20
/* ... */
#define USB_CDC_REQ_SET_CONTROL_LINE_STATE	0x22
/* ... */

/* Table 17: Line Coding Structure */
struct usb_cdc_line_coding {
	uint32_t dwDTERate;
	uint8_t bCharFormat;
	uint8_t bParityType;
	uint8_t bDataBits;
} __attribute__((packed));

/* Table 30: Class-Specific Notification Codes for PSTN subclasses */
/* ... */
#define USB_CDC_NOTIFY_SERIAL_STATE	0x28
/* ... */


/* Notification Structure */
struct usb_cdc_notification {
	uint8_t bmRequestType;
	uint8_t bNotification;
	uint16_t wValue;
	uint16_t wIndex;
	uint16_t wLength;
} __attribute__((packed));

#endif

