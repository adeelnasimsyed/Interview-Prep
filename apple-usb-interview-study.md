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

The above driver is registered by calling **usb_register** function in the driver **__init** function. The driver should call **usb_deregister** in the driver **__exit** function.

The kernel module defines the **__init** and **__exit** functions using the **moduel_init** and **module_exit** defines
