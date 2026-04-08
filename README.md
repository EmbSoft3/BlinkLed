# BlinkLed
**BlinkLed** is a minimal dynamic application for the [Mk](https://github.com/EmbSoft3/Mk) operating system. It blinks the user LED board and is intended as a getting-started example showing how to build, install, and run an external `.elf` application on top of Mk.

---

## Installation

Build the application (see [Build](#build) below), then copy `blinkLed.elf` and its
icon `mk_blinkLed.bmp` to the Mk file system at:

```
mk/apps/blinkLed/
```

This path corresponds to [`Mk/Storage/mk/apps/blinkLed/`](https://github.com/EmbSoft3/Mk/tree/main/Mk/Storage/mk/apps/blinkLed)
in the Mk repository. Once installed, BlinkLed appears in the Mk home screen application list.

---

## Build

### Requirements

- [GNU Arm Embedded Toolchain 10.3-2021.10](https://developer.arm.com/downloads/-/gnu-rm) — must be added to your `PATH`
- CMake ≥ 3.25
- Ninja
- [Mk Includes](https://github.com/EmbSoft3/Mk/tree/main/Mk/Includes) — must be present at `../Mk/Mk/Includes` relative to the project root

### Build system

The project uses **CMake** with presets defined in `CMakePresets.json`:

| Preset | Type | Description |
|--------|------|-------------|
| `release-BlinkLed` | Release | Optimised build (`-Ofast`), stripped |
| `debug-BlinkLed` | Debug | Unoptimised build (`-O0 -g3`) with full debug symbols |

### Steps

1. Make sure `arm-none-eabi-gcc` is in your `PATH`:
   ```bash
   arm-none-eabi-gcc --version
   ```

2. Make sure the [Mk Includes](https://github.com/EmbSoft3/Mk/tree/main/Mk/Includes) directory
   is present at `../Mk/Mk/Includes` relative to the project root, or update `INCLUDES_API_PATH`
   in `CMakePresets.txt` accordingly.

3. Configure the project using the desired preset:
   ```bash
   cmake --preset release-BlinkLed
   ```

4. Build the firmware:
   ```bash
   cmake --build --preset release-BlinkLed
   ```

   This produces in `build/release-BlinkLed/`:
   - `blinkLed.elf` — position-independent shared object, ready to install on the target
   - `blinkLed.map` — linker map file

> Use the `debug-BlinkLed` preset for an unoptimised build with full debug symbols:
> ```bash
> cmake --preset debug-BlinkLed
> cmake --build --preset debug-BlinkLed
> ```

The application is compiled as a position-independent shared object (`-fPIC -shared`) and is
relocatable into any 64 KB SDRAM page by the Mk dynamic loader.

### Compiler versions used

| Tool | Version |
|------|---------|
| `arm-none-eabi-gcc` | 10.3.1 20210824 (GNU Arm Embedded Toolchain 10.3-2021.10) |
| `arm-none-eabi-g++` | 10.3.1 20210824 (GNU Arm Embedded Toolchain 10.3-2021.10) |
| CMake | ≥ 3.25 |
| Ninja | latest |

---

## Writing your own application

BlinkLed is the reference example for the Mk application model. For a step-by-step guide
on how to structure your own Mk application — descriptor, entry point, event listeners,
memory layout — see the [Mk wiki](https://github.com/EmbSoft3/Mk/wiki/Writing%E2%80%90Your%E2%80%90First%E2%80%90Application).

---

## License

**Copyright (C)** 2024 **RENARD Mathieu**. All rights reserved.

Mk is free software; It is distributed in the hope that it will be useful.
There is NO warranty; not even for MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.

The content of this repository is bound by the [BSD-3-Clause](LICENSE) license.
