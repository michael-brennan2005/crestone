Crestone is a chip8 emulator I'm making in order to learn emulation and also C++ development.

**Building for Linux**  
Crestone's only dependency is SFML, whose Linux version libraries are included in libs/. Build configuration is done with CMake.

This command should do everything for you:
```cmake -G "Ninja" . && ninja && ./crestone-exe```

**Building for Windows**  
Building for Windows is mostly the same process - Windows version libraries are in libs/, CMake does the configuration for you - but there are a few caveats.

1. Compilation must be done with Visual C++ 2015 17 with an amd64 target. That's what the pre-built SFML libraries were compiled to, and according to their docs the library will only work with that compiler.
2. You need to have the SFML .dll's in the same folder as the executable, or else the program will throw errors.
