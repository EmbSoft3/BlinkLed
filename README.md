# BlinkLed

**BlinkLed** is a minimal dynamic application for the [Mk](https://github.com/EmbSoft3/Mk) OS. It blinks the user LED of the **STM32F746G-Eval2** board and is intended as a getting-started example showing how to build, install, and run an external `.elf` application on top of Mk.

---

## Build

**BlinkLed** can be built using the [makefile](BlinkLed/Make/makefile) file on the repository.

The variable **TOOLCHAIN\_PATH** must be updated with the path of the ARM toolchain.
The variable **INCLUDES\_API\_PATH** must be updated with the
[include path](https://github.com/EmbSoft3/Mk/tree/main/Mk/Includes) of
the **Mk** operating system.

First, issue a **make clean** command then build the target with **make all**.

This produces `blinkLedRelease.elf` in `BlinkLed/Make/`. 
The application is compiled as a position-independent shared object (`-fPIC -shared`) and is relocatable into any 64 KB SDRAM page by the Mk dynamic loader.

Currently versions of compiler used are the followings:

* **gcc** arm-none-eabi-gcc (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1
  20210824 (release)
* **g++** arm-none-eabi-g++ (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1
  20210824 (release)
* **make** GNU Make 4.4.1 Built for Windows32

Please note, that by default, the application is compiled in release mode with
optimizations enabled (**-Ofast**).

---

## Installation and execution

Copy the built `.elf` file and the [icon](BlinkLed/Storage/) to the `mk/apps/blinkLed` directory on the storage device (SD card or USB flash drive) used by the target board.

Once Mk is running, **BlinkLed** is installed by default. Click on the icon to run the application.

---

## License

**Copyright (C)** 2024 **RENARD Mathieu**. All rights reserved.

Mk is free software; It is distributed in the hope that it will be useful.
There is NO warranty; not even for MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.

The content of this repository is bound by the [BSD-3-Clause](LICENSE) license.
