# Peanut OS
a monolithic kernel operating system for the x86 computer architecture

# Features

- 32-bit bootloader
- video bitmap based graphics driver 
- keyboard driver
- CPU emulator
- kernel

## Roadmap

- migrate from 32 to 64 bit
	- reimplement bootloader to enter long mode and use paging
	- support multiboot mode, switch from BIOS to UEMFI
	- extend kernel for panic mode and more meta commands
- a file System
- network drivers 

## Installation

Note: Make sure you have a GCC cross compiler installed.  
clone the repo
```bash
    git clone https://github.com/jvmespark/Peanut-OS.git
    make run
```

## Resources

 - https://dev.to/frosnerd/series/9585
 - https://github.com/cfenollosa/os-tutorial
 - https://github.com/Stichting-MINIX-Research-Foundation/minix/tree/master/minix
 - https://wiki.osdev.org
 - https://www.youtube.com/watch?v=1rnA6wpF0o4&list=PLHh55M_Kq4OApWScZyPl5HhgsTJS9MZ6M
