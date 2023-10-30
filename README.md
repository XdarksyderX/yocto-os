# Yocto-OS

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![License](https://img.shields.io/badge/license-MIT-green)

## Overview

**Yocto-OS** is a minimalistic operating system built for educational purposes. The name "Yocto" denotes its incredibly small size. Although it was initially written mainly in Assembly, this project has now evolved to provide deeper insights into the low-level mechanisms of operating systems, from bootloading to kernel functionalities. The project has shifted towards the UEFI environment and is primarily written in C.

## Features

- 🚀 Extremely lightweight and minimal codebase.
- 📚 Educational comments explaining the logic.
- 💼 Uses the NASM assembler for compilation in its assembly parts.
- 💼 Written in C for UEFI and kernel functionalities.
- 💾 FAT12 Filesystem support.
- 🛡️ Incorporates `limine` as the bootloader for UEFI.

## Prerequisites

- NASM (Netwide Assembler)
- GNU Make
- QEMU (for emulation, optional)
- Development tools for C
- xorriso
- mtools
- gd

## Building

To build the project, navigate to the root directory and run:

```bash
bash run.sh
