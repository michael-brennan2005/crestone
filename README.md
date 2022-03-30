Crestone is a chip8 emulator I'm making in order to learn emulation and also C++ development.

**Building**
Crestone's only dependency is SFML, whose Linux version libraries are included in libs/. Build configuration is done with CMake.

This command should do everything for you:
```cmake -G "Ninja" . && ninja && ./crestone-exe```