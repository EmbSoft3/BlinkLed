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

#### All platforms
- [GNU Arm Embedded Toolchain 10.3-2021.10](https://developer.arm.com/downloads/-/gnu-rm) — must be added to your `PATH`
- GNU Make 4.3
- [Mk Includes](https://github.com/EmbSoft3/Mk/tree/main/Mk/Includes)

#### Windows only (one of the following)
- [MSYS2](https://www.msys2.org/) *(recommended)* — provides `sh`, `find`, `rm` and other Unix tools required by the Makefile
- [Git for Windows](https://git-scm.com/) — Git Bash ships the same Unix tools

> The Makefile automatically detects MSYS2 or Git Bash at their default installation
> paths (`C:/msys64` and `C:/Program Files/Git`). If your installation is elsewhere,
> update `MSYS2_BIN` or `GITBASH_BIN` at the top of `BlinkLed/Make/Makefile`.

### Steps

1. Clone the repository and make sure the [Mk Includes](https://github.com/EmbSoft3/Mk/tree/main/Mk/Includes) directory is present at `../../Mk/Mk/Includes` relative to the `Make` directory, or update `INCLUDES_API_PATH` in `BlinkLed/Make/Makefile` accordingly.

2. Add `arm-none-eabi-gcc` to your `PATH` (verify with `arm-none-eabi-gcc --version`).

3. Build:

```bash
make clean
make all        # Release build — optimised, stripped
```

This produces `blinkLedRelease.elf`, ready to install on the target.

> Use the `Debug` target for a `-O0` build with full debug symbols:
> ```bash
> make Debug
> ```

The application is compiled as a position-independent shared object (`-fPIC -shared`) and is relocatable into any 64 KB SDRAM page by the Mk dynamic loader.

### Available targets

| Target    | Description                                              |
|-----------|----------------------------------------------------------|
| `all`     | Alias for `Release`                                      |
| `Release` | Optimised build (`-Ofast`), stripped                     |
| `Debug`   | Unoptimised build (`-O0`) with full debug symbols        |
| `clean`   | Remove all generated files (`.o`, `.d`, `.su`, `.elf`, `.map`) |

### Compiler versions

| Tool | Version |
|------|---------|
| `arm-none-eabi-gcc` | 10.3.1 20210824 (GNU Arm Embedded Toolchain 10.3-2021.10) |
| `arm-none-eabi-g++` | 10.3.1 20210824 (GNU Arm Embedded Toolchain 10.3-2021.10) |
| `make` | GNU Make 4.3 |

---

## Continuous Integration

Every push and pull request is automatically built by **GitHub Actions**.
The workflow installs the GNU Arm Embedded Toolchain, runs `make Release`,
and uploads `blinkLedRelease.elf` as a downloadable build artifact.

The latest successful build artifact is available on the
[Actions](../../actions) tab of this repository.

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
