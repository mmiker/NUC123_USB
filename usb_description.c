/**
  *****************************************************************************
  * @title   descriptors.c
  * @author  CooCox
  * @date    23 Sep 2014
  * @brief   Demonstrate how to implement a USB virtual com port device.
  *          It
  *          supports one virtual comport.
  *******************************************************************************
  */
////// The above comment is automatically generated by CoIDE ///////////////////

/******************************************************************************
 * @file     descriptors.c
 * @brief    NUC123 series USBD driver source file
 * @version  2.0.0
 * @date     22, March, 2013
 *
 * @note
 * Copyright (C) 2013 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef __USB_DESCRIPTORS_C__
#define __USB_DESCRIPTORS_C__

/*!<Includes */
#include "NUC123.h"
#include "usbd.h"
#include "usb_description.h"

/*----------------------------------------------------------------------------*/
/*!<USB Device Descriptor */
uint8_t gu8DeviceDescriptor[] =
{
    LEN_DEVICE,     /* bLength */
    DESC_DEVICE,    /* bDescriptorType */
    0x00, 0x02,     /* bcdUSB */
    0x00,           /* bDeviceClass */
    0x00,           /* bDeviceSubClass */
    0x00,           /* bDeviceProtocol */
    EP0_MAX_PKT_SIZE,   /* bMaxPacketSize0 */
    /* idVendor */
    USBD_VID & 0x00FF,
    (USBD_VID & 0xFF00) >> 8,
    /* idProduct */
    USBD_PID & 0x00FF,
    (USBD_PID & 0xFF00) >> 8,
    0x00, 0x01,     /* bcdDevice */
    0x01,           /* iManufacture */
    0x02,           /* iProduct */
    0x00,           /* iSerialNumber - no serial */
    0x01            /* bNumConfigurations */
};

/*!<USB Configure Descriptor */
uint8_t gu8ConfigDescriptor[] =
{
    LEN_CONFIG,     /* bLength              */
    DESC_CONFIG,    /* bDescriptorType      */
    0x42 , 0x00,     /* wTotalLength         */
    0x02,           /* bNumInterfaces       */
    0x01,           /* bConfigurationValue  */
    0x00,           /* iConfiguration       */
    0xC0,           /* bmAttributes         */
    0x32,           /* MaxPower             */

    /* Interface association descriptor IAD */
    0x08,           /* bLength              */
    0x0B,           /* bDescriptorType      */ /* Interface Association*/
    0x00,           /* bFirstInterface      */
    0x02,           /* bInterfaceCount      */
    0x02,           /* bFunctionClass       */ /* CDC Control */
    0x02,           /* bFunctionSubClass    */ /* Abstract Control Model */
    0x01,           /* bFunctionProtocol    */ /* AT Commands: V.250 etc */
    0x00,           /* iFunction            */

    /* INTERFACE descriptor 0/0 CDC Control, 1Endpoint */
    LEN_INTERFACE,  /* bLength              */
    DESC_INTERFACE, /* bDescriptorType      */ /* Interface */
    0x00,           /* bInterfaceNumber     */
    0x00,           /* bAlternateSetting    */
    0x01,           /* bNumEndpoints        */
    0x02,           /* bInterfaceClass      */ /* CDC Control */
    0x02,           /* bInterfaceSubClass   */ /* Abstract Control Model */
    0x01,           /* bInterfaceProtocol   */ /* AT Commands: V.250 etc */
    0x00,           /* iInterface           */

    /* Header Functional Descriptor */
    0x05,           /* bFunctionLength      */
    0x24,           /* bDescriptorType      */ /* CS Interface */
    0x00,           /* bDescriptorSubType   */ /* Header */
    0x10,0x01,      /* bcdCDC               */ /* 1.10 */

    /* Call Management Functional Descriptor*/
	0x05,		    /* bFunctionLength      */
	0x24,	        /* bDescriptorType      */ /* CS_INTERFACE */
	0x01,           /* bDescriptorSubtype   */ /* Call Management */
	0x00,		    /* bmCapabilities       */ /* device handles call management */
	0x01,	        /* bDataInterface       */ /* CDC data IF ID */

    /* ENDPOINT descriptor 82 2 In, Interrupt, 2ms */
    LEN_ENDPOINT,                   /* bLength          */
    DESC_ENDPOINT,                  /* bDescriptorType  */ /* Endpoint */
    (EP_INPUT | CDC_INT_IN_EP_NUM), /* bEndpointAddress */ /* 2 In */
    EP_INT,                         /* bmAttributes     */ /* Interrupt */
    EP2_MAX_PKT_SIZE, 0x00,         /* wMaxPacketSize   */ /* 8 byte */
    0x01,                           /* bInterval        */ /* 2ms */

    /* INTERFACE descriptor 1/0 CDC Data, 2 Endpoint */
	LEN_INTERFACE,  /* bLength              */
	DESC_INTERFACE, /* bDescriptorType      */ /* Interface */
	0x01,           /* bInterfaceNumber     */
	0x00,           /* bAlternateSetting    */
	0x02,           /* bNumEndpoints        */
	0x0A,           /* bInterfaceClass      */ /* CDC Data */
	0x00,           /* bInterfaceSubClass   */
	0x00,           /* bInterfaceProtocol   */
	0x00,           /* iInterface           */

    /* ENDPOINT descriptor 03 3 Out, Bulk, 32 bytes */
    LEN_ENDPOINT,                      /* bLength          */
    DESC_ENDPOINT,                     /* bDescriptorType  */ /* Endpoint */
    (EP_OUTPUT | CDC_BULK_OUT_EP_NUM), /* bEndpointAddress */ /* 3 Out */
    EP_BULK,                           /* bmAttributes     */ /* Bulk */
    EP3_MAX_PKT_SIZE, 0x00,            /* wMaxPacketSize   */ /* 32 byte */
    0x01,                              /* bInterval        */ /* 2ms */

    /* ENDPOINT descriptor 83 3 In, Bulk, 64 bytes */
    LEN_ENDPOINT,                      /* bLength          */
    DESC_ENDPOINT,                     /* bDescriptorType  */ /* Endpoint */
    (EP_INPUT | CDC_BULK_IN_EP_NUM),   /* bEndpointAddress */ /* 83 In */
    EP_BULK,                           /* bmAttributes     */ /* Bulk */
    EP4_MAX_PKT_SIZE, 0x00,            /* wMaxPacketSize   */ /* 64 byte */
    0x01,                              /* bInterval        */ /* 2ms */

};

/*!<USB Language String Descriptor */
uint8_t gu8StringLang[4] =
{
    4,              /* bLength */
    DESC_STRING,    /* bDescriptorType */
    0x09, 0x04
};

/*!<USB Vendor String Descriptor */
uint8_t gu8VendorStringDesc[] =
{
    16,
    DESC_STRING,
    'N', 0, 'u', 0, 'v', 0, 'o', 0, 't', 0, 'o', 0, 'n', 0
};

/*!<USB Product String Descriptor */
uint8_t gu8ProductStringDesc[] =
{
    32,             /* bLength          */
    DESC_STRING,    /* bDescriptorType  */
    'U', 0, 'S', 0, 'B', 0, ' ', 0, 'D', 0, 'E', 0, 'B', 0, 'u', 0, 'G', 0, ' ', 0, 'C', 0, ' ', 0, 'A', 0, 'R', 0, 'D', 0
};

S_USBD_INFO_T gsInfo =
{
    gu8DeviceDescriptor,
    gu8ConfigDescriptor,
    gu8StringLang,
    gu8VendorStringDesc,
    gu8ProductStringDesc,
    NULL,
};

#endif  /* __DESCRIPTORS_C__ */
