# Yocto-OS

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![License](https://img.shields.io/badge/license-MIT-green)

## Overview

**Yocto-OS** is a minimal operating system built for educational purposes. The name "Yocto" is indicative of its incredibly small size. Written primarily in Assembly, this project aims to provide insights into the low-level workings of operating systems, from bootloading to kernel functionalities.

## Features

- 🚀 Super lightweight and minimal codebase
- 📚 Educational comments explaining the logic
- 💼 NASM assembler for compilation
- 💾 FAT12 Filesystem support
- 🛡️ Includes a basic bootloader

## Prerequisites

- NASM (Netwide Assembler)
- GNU Make
- QEMU (for emulation, optional)

## Building

To build the project, navigate to the root directory and run:

```bash
make all
