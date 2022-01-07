<div id="top"></div>

<div align="center">
  <a>
    <img src="https://github.com/beastrun12j/PokeMania/blob/master/Game/resources/img/game-title.png" alt="Logo">
  </a>

<h4 align="center">Pokemon-Themed 2-D Single Person Arcade Game</h4>

  <p align="center">
    <a href="https://github.com/beastrun12j/PokeMania/blob/master/Demo.mp4">View Demo</a>
    ·
    <a href="https://github.com/beastrun12j/PokeMania/issues">Report Bug</a>
  </p>
</div>

# About The Project

<p align="center">
  <img src="https://user-images.githubusercontent.com/79413577/148220619-e18ae8d2-28ab-4d2a-b62b-e599982dc4eb.gif" height="420px"/>
  <img src="https://user-images.githubusercontent.com/79413577/148220652-024c65a1-b7bf-49fa-babe-9c6f3759bfba.gif" height="420px"/>
</p>

PokeMania is a rendition over the very famous Flappy Bird Game with additional features. We made this game basically as a part of our Computer Graphics Project in college.

### Built With

* [C++](https://en.cppreference.com/w/)
* [SFML Library](https://www.sfml-dev.org)

#### About SFML:

Simple and Fast Multimedia Library (SFML) is a cross-platform software development library designed to provide a simple application programming interface (API) to various multimedia components in computers. It is written in C++ with bindings available for other languages

#### Why SFML:
* SFML is perfect for writing 2D games of any size or complexity at all
* It provides cross-platform compatibility and as its name suggests it is easy to learn and use
* It is free, open-sourced and has a good community for discussions and problems
* Lastly, It also provides a graphics module for simple hardware acceleration of 2D computer graphics which includes text rendering using FreeType, an audio module that uses OpenAL and a networking module for basic Transmission Control Protocol (TCP) and User Datagram Protocol (UDP) communication.

Of course, It is not an all-in-one solution for all your game development needs like Unreal Engine, CryEngine or Unity. It will not let you design huge realistic 3d worlds, build 3d models or create movie-like cut-scenes. But for us being beginners at game development, it is great source of learning.

## Prerequisites

### Windows

- [SFML 2.5.1 - GCC 7.3.0 MinGW (DW2) 32-bit (for Windows)](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip)
- [GCC 7.3.0 MinGW (DW2) 32-bit (for Windows)](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download)
- [Git Bash (for Windows) ](https://git-scm.com/downloads)

### MacOS

- [SFML 2.5.1 - Clang 64-bit](https://www.sfml-dev.org/files/SFML-2.5.1-macOS-clang.tar.gz)
- Command Line Tools / XCode (type "xcode-select --install" in terminal to trigger the installer)

### Linux

- Get SFML 2.5.1 from your distro if it has it, or compile from source

### All

- [Visual Studio Code](https://code.visualstudio.com/download)
- Extensions (install from Extensions panel):
- [Official C/C++ Extension (0.21.0+)](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  
## Installation

### Windows

1. Download & Extract SFML to **C:/SFML-2.5.1/** where the bin/lib/include folders are contained within
2. Download & Extract MinGW to **C:/mingw32/** where the bin/lib/include folders are contained within

### MacOS

1. Install "Command Line Tools" in MacOS if they're not already installed (type "xcode-select --install" in terminal)
2. Follow the "Installing SFML" directions here: https://www.sfml-dev.org/tutorials/2.5/start-osx.php#installing-sfml

### Linux

1. Ensure the GCC Toolchain is installed (**sudo apt install build-essential**) (**sudo pacman -S base-devel**)
2. Install libsfml (**sudo apt install libsfml-dev**) (**sudo pacman -S sfml**). The SFML version you got will vary depending on the distro. 2.5.1 is included in [Ubuntu 19.04 Disco Dingo](http://cdimage.ubuntu.com/daily-live/current/HEADER.html) for example.

### All

3. Download & Install Visual Studio Code if you don't already have it.
4. Install the official **C/C++** Extension, reload the window & wait for the dependencies to install.
5. If on Windows, install **Git Bash**, and ensure the **"terminal.integrated.shell.windows"** property in the project's **settings.json** is set to **bash.exe**'s correct location (default: C:/Program Files/Git/bin/bash.exe). We'll be using this for the terminal in our workspace so that the Makefile can run in both Windows, Mac & Linux
6. In **settings.json** Ensure **Path** in the **terminal.integrated.env.windows** object is set to the correct location of the compiler's executable (example: C:\\mingw32\\bin) and the SFML directory is correct as well. Keep in mind Paths should be separated by a semi-colon with no spaces between.

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Our Team

| <img src="https://avatars.githubusercontent.com/u/79413577?v=4" alt="Pranav Tiwari" style="width:200px;"/> | <img src="https://avatars.githubusercontent.com/u/20703579?v=4" alt="Rishabh Jain" style="width:200px;"/> | <img src="" alt="" style="width:200px;"/>  | <img src="" alt="" style="width:200px;"/>  |
|----------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------|---|---|
| [Pranav Tiwari](https://github.com/beastrun12j)                                                          | [Rishabh Jain](https://github.com/Rishabhjain8)                                                           | []()  |  []() |

<p align="right"><a href="#top">Back to top</a></p>
