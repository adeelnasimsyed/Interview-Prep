The first thing the Linux USB driver has to do is register itself with the USB subsystem

```
static struct usb_driver skel_driver = 
{
        .name        = "skeleton", //human readable name 
        .probe       = skel_probe, // function called when new device is connected
        .disconnect  = skel_disconnect, //function called when device is disconnected
        .fops        = &skel_fops, // file operations, read, write, open, close
        .minor       = USB_SKEL_MINOR_BASE, //
        .id_table    = skel_table,
};
```

The above driver is registered by calling **usb_register** function in the driver **__init** function. 
The driver should call **usb_deregister** in the driver **__exit** function.

The kernel module defines the **__init** and **__exit** functions using the **moduel_init** and **module_exit** defines

The driver defines a table of vendor ids and product ids, that are registered with the Linux USB subsystem.
When a USB device is hotplugged, the subsystem will find the kernel module (driver) that matches the vendor id and product id
and load the driver.

```
/* table of devices that work with this driver */
static struct usb_device_id skel_table [] = {
        { USB_DEVICE(USB_SKEL_VENDOR_ID, USB_SKEL_PRODUCT_ID) },
        { }                      /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, skel_table);
```

When a device is plugged in that matches one of the **usb_device_id** elements on the list our driver registered, the OS will
call the **probe** function of our driver. The driver will verify if it can accept this device.

After the device is plugged, the functions defined in the fileoperations can be called. The first one is the **open** function.

After the **open** function, the **read** and **write** functions can be called by the user level in order to interact with our usb device.

The **release** function is called when a user level program releases the file handle of our device. 

