# KrampusOS

KrampusOS is a small, homebrew operating system written entirely in **C**, designed as a long-term learning and experimentation project.  
The system begins as a minimal kernel providing a basic shell capable of executing simple commands, but the ultimate vision is far more ambitious:  
to evolve KrampusOS into a retro-styled fantasy computer capable of running small games, demos, and custom software built specifically for this environment.

KrampusOS is intentionally simple, modular, and transparent, making it an ideal playground for anyone interested in operating systems, low-level programming, retro-computing, or game development on constrained hardware models.

---

## Project Goals

- Provide a **minimal bootable kernel** with a basic interactive shell.
- Offer a clean and understandable codebase for **OS development learning**.
- Gradually expand into a **retro fantasy machine**, inspired by early home computers.
- Allow development of **simple games and applications**, either directly in C or using custom scripting tools planned for the future.
- Emulate a nostalgic environment where developers can:
  - Create small programs  
  - Explore low-level concepts  
  - Tinker with system internals  
  - Learn how kernels, drivers, shells, and memory management work  

This system is not intended to compete with modern operating systems, but to serve as an exploration space and experimental playground.

---

## Technologies & Toolchain

KrampusOS is built with a cross-compilation environment using the **i686-elf** target.

### **Compiler**
- `i686-elf-gcc`

### **Linker**
- `i686-elf-ld`

### **Emulator**
Development and testing are performed using **QEMU**, specifically:

```bash
qemu-system-i386 -kernel krampusos.bin
```

This allows fast iteration and testing without requiring real hardware.

---

## Current Features (MVP Stage)

- Bootable kernel image
- Basic initialization routines
- Simple command shell with minimal commands
- Text-mode VGA output

(Features will expand steadily as development continues.)

---

## Future Plans

KrampusOS aims to grow into a **retro workstation / fantasy console hybrid**. Planned features include:

- Basic filesystem support  
- Custom executable/game format  
- Improvements to the shell (commands, scripting, pipelines)  
- Simple graphics API for 2D games  
- Sound output  
- Virtual machine–like environment for consistent behavior across platforms  
- Tooling for building and packaging small games or demos  

The long-term goal is to offer an environment reminiscent of old 8-bit and 16-bit machines while still allowing modern development techniques.

---

## Building KrampusOS

You will need a properly configured cross-compiler targeting `i686-elf`.  
After setting up the toolchain, building the kernel typically looks like:

```bash
make
```

(or equivalent build instructions once Makefiles are finalized)

Then run it in QEMU:

```bash
qemu-system-i386 -kernel krampusos.bin
```

---

## License

KrampusOS is released under the **GNU General Public License v3.0**.  
See the `LICENSE` file for full details.

---

## Contributing

Contributions are welcome!  
Whether you want to improve documentation, suggest new features, fix bugs, or help expand the kernel, feel free to open issues or submit pull requests.

---

## Why “KrampusOS”?

Krampus, the mythical creature often depicted as the mischievous counterpart to Santa Claus, represents the playful and experimental spirit of this project.  
KrampusOS embraces curiosity, creativity, and a bit of chaos—the perfect ingredients for a homebrew operating system.

---

## Disclaimer

KrampusOS is an educational and experimental project.  
It is **not** intended for production use, real workloads, or secure environments. Expect bugs, odd behavior, and constant evolution.

---

Thanks for checking out KrampusOS!  
Stay tuned as this little retro creature grows into a full-fledged fantasy operating system. 👾
