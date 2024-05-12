# Boilerplate Makefile
A simple Makefile for medium to large projects that supports resolution of 3rd party dependencies. 

## Requirements
### Linux
> Installation commands are relative to your distributions package repository. Ubuntu for example would require `sudo apt install pkgconf`.
- GNU Make 
- GCC or Clang
- pkg-config or pkgconf (optional)
    - This would be required if you were using 3rd party libraries in your code such as the ncurses development libraries.

### Windows
- MinGW-W64 Environment through [MSYS2](https://www.msys2.org/)
- [MinGW-W64 Toolchain](https://packages.msys2.org/basegroups/mingw-w64-toolchain)
    - `pacman -S mingw-w64-[platform]-toolchain`
> You will need to replace the usage of `make` with `mingw32-make`. The work around is to alias `mingw32-make` as `make` in your `.bashrc` (or similar) file.

## Usage
To use this template, run `make` (`mingw32-make` on Windows) in the same directory as the `Makefile`. This will compile, link and resolve the project dependencies (if there are any) and output your named executable in the `bin` directory.

## Simple Directory Structure
Right out of the box this Makefile supports a `src`, `bin` layout structure but it can be easily modified if you prefer to keep your header files separate or use a different structure.
```
bin
└ my-project-executable
src
├ main.c
├ my_lib.h
└ my_lib.c
```
