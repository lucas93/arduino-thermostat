# Arduino - Unit Testing and Development

This repository contains an example project build based on CMake, 
allowing both Arduino development and Unit Testing, with a convinient 
file structure. For some enthusiasts (like me ;) ) it provides a 
simple solution to practice Test Driven Development (TDD) for 
Arduino projects. The following project could de easily adjusted to
other platforms, like Raspberry Pi.

Many thanks for [Crascit][1] for sharing the tools allowing to 
easily integrate with Google Test. Also thanks to [queezythegreat][2],
from whoom i got a simple-to-use Arduino build system.

I reccomend QtCreator as the IDE, for it handles the CMake-based 
projects preety well. Of course, any developing tools will do,
and CMake can be used directly.

# Mocking environment

I'm using my own library for convinient and memory-safe mocking
of global arduino objects (like Serial) in a local scope. Also
global functions from Arduino.h are mockable.

# Uploading to Arduino

The sketch is uploaded to board bo command line tools. Just look
how Arduino IDE does that and mirror the terminal commands.



Tested on Linux.

[1]: https://github.com/Crascit/DownloadProject
[2]: https://github.com/queezythegreat/arduino-cmake
