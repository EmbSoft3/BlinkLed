# BlinkLed

**BlinkLed** is a minimal dynamic application for the [Mk](https://github.com/EmbSoft3/Mk) OS. It blinks the user LED of the **STM32F746G-Eval2** board and is intended as a getting-started example showing how to build, install, and run an external `.elf` application on top of Mk.

---

## Installation

Build the application (see [Build](#build) below), then copy `blinkLedRelease.elf` and its
icon `mk_blinkLed.bmp` to the Mk file system at:

```
mk/apps/blinkLed/
```

This path corresponds to [`Mk/Storage/mk/apps/blinkLed/`](https://github.com/EmbSoft3/Mk/tree/main/Mk/Storage/mk/apps/blinkLed)
in the Mk repository. Once installed, BlinkLed appears in the Mk home screen application list.

---

## Build

### Requirements

- [GNU Arm Embedded Toolchain 10.3-2021.10](https://developer.arm.com/downloads/-/gnu-rm)
- GNU Make 4.x
- [Mk Includes](https://github.com/EmbSoft3/Mk/tree/main/Mk/Includes)

### Steps

1. Open `BlinkLed/Make/makefile` and set:
   - `TOOLCHAIN_PATH` — path to your ARM toolchain `bin/` directory
   - `INCLUDES_API_PATH` — path to the Mk [`Includes/`](https://github.com/EmbSoft3/Mk/tree/main/Mk/Includes) directory

2. Build:

```
make clean
make all
```

This produces `blinkLedRelease.elf`, ready to install on the target.

> Use the `Debug` target for a `-O0` build with full debug symbols:
> ```
> make Debug
> ```

The application is compiled as a position-independent shared object (`-fPIC -shared`) and is relocatable into any 64 KB SDRAM page by the Mk dynamic loader.

### Compiler versions

| Tool | Version |
|------|---------|
| `arm-none-eabi-gcc` | 10.3.1 20210824 (GNU Arm Embedded Toolchain 10.3-2021.10) |
| `arm-none-eabi-g++` | 10.3.1 20210824 (GNU Arm Embedded Toolchain 10.3-2021.10) |
| `make` | GNU Make 4.4.1 (Windows32) |

---

## Writing your own application

BlinkLed is the reference example for the Mk application model. For a step-by-step guide
on how to structure your own Mk application — descriptor, entry point, event listeners,
memory layout — see the [Mk wiki](https://github.com/EmbSoft3/Mk/wiki/Writing-Your-First-Application).

---

## License

**Copyright (C)** 2024 **RENARD Mathieu**. All rights reserved.

Mk is free software; It is distributed in the hope that it will be useful.
There is NO warranty; not even for MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.

The content of this repository is bound by the [BSD-3-Clause](LICENSE) license.
