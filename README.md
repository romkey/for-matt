# PlatformIO Starter

This is a very basic PlatformIO project for the [Unexpected Maker Feather S3](https://unexpectedmaker.com/shop/feathers3).

The project is a simple Arduino C++ program that outputs "Hello World" on the serial port at 115200 bits per second, and then blinks the board's blue LED.

The C++ source is in `src/main.cpp`. This is just a convention; you could use any filename in `src`, though it's important to use `.cpp` to tell the compiler it's a C++ file.

Under the Arduino IDE, the same file's name would end in `.ino` and the first part would be the name of the project. PlatformIO will recognize `.ino` files as C++ but you should really use `.cpp` with it.

To build it from the command line, go to its top level directory and run:
```
platformio run
```

PlatformIO will download any tools or packages it needs to build the program. Then it will compile and link the program. You'll many files that aren't main.cpp being compiled; these are the Arduino framework and the underlying software it's built on. The next time you build the project, files will only be recompiled if they've changed, if a file they depend on has changed, or if `platformio.ini` has changed.

To flash the program to the Feather S3, first put it in download mode. Press and hold the BOOT button, then press and release the RESET button, then release the boot button. You should now see a device whose name looks like `/dev/tty.usbmodem-010`. The exact suffix will vary. You can check for this from the shell:
```
ls /dev/tty.usb*
```

This should show the device. If it doesn't appear then try to BOOT/RESET button sequence again, and double check that you're using a USB data cable and not charging cable.

Once the device appears you can flash your code to the ESP32 by running:
```
platformio run -t upload
```

That should show you progress as the firmware is copied to the flash memory on the Feather S3. Once this is done, the program will remain on the ESP32 even if power is removed. The next time the Feather S3 is powered on or reset the program will run.

Now start a serial monitor so you can see the program's output:
```
platformio device monitor
```

PlatformIO will display the serial device it's using. It should be `/dev/cu.usbSOMETHING` or `/dev/tty.usbSOMETHING` (they're the same thing). If it shouws you `/dev/cu.Bluetooth-Incoming-Port` then it's found the wrong serial port and you should verify that the correct one exists and try again.


And press the RESET button on the Feather S3. This should disconnect the monitor briefly. After it comes back you should see "Hello World" and the blue LED should start flashing.

You can also skip this step and just press RESET; you won't see the message but the blue LED should still flash.

Good luck!
