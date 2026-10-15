# IRCabie Darkfall Fullstack

A high-performance audio plugin and GUI background interface built with **JUCE** and **CMake**, designed for full-stack dark amplifier and cabinet Impulse Response (IR) processing.

## Features

* **JUCE Framework**: Modern, cross-platform audio plugin architecture.
* **Cabinet IR Loader**: Core WAV-based Impulse Response processing engine.
* **Custom Visual GUI**: Custom background graphics integrated with vertical filmstrip knobs and toggles.
* **Cross-Platform Support**: Ready to compile on Windows (MSVC Visual Studio 2019 x64), Linux (`g++` / standard `make`), and macOS (Xcode).

## Asset Bundle (`BinaryData`)

The project uses JUCE's `BinaryData` target to embed static assets directly into the binary:

* `background.bmp` — Main UI fullstack amplifier background graphic.
* `knob_vertical_sprites.png` — Vertical filmstrip sprite sheet for continuous knobs.
* `toggle_knob_vertical_sprites` — Sprite sheet for toggle/switch elements.
* `icon.ico` — Application and plugin bundle icon.

## Requirements

### General Dependencies

* **JUCE 7.0.9** (or newer)
* **CMake** `3.22+`
* **Git**

### Platform-Specific Compilers & Build Tools

* **Windows**: Visual Studio 2019 (MSVC x64 toolset)
* **Linux**: `g++` / GCC, `make`, and standard Audio API dependencies (`libasound2-dev`, `libfreetype6-dev`, `libx11-dev`, `libxinerama-dev`, `libxext-dev`, `libcurl4-openssl-dev`)
* **macOS**: Xcode / Xcode Command Line Tools

---

## Building the Project

### 1. Clone the Repository

```bash
git clone https://github.com/fajarjulyana/QWare_IRCabie.git
cd QWare_IRCabie
```

### 2. Build Instructions

#### Windows (Visual Studio 2019 x64 Debug)

```cmd
cmake -B build -G "Visual Studio 16 2019" -A x64
cmake --build build --config Debug
```

#### Linux (Standard Makefile & `g++`)

```bash
cmake -B build
cd build
make -j$(nproc)
```

#### macOS (Xcode Direct Compile)

```bash
cmake -B build -G Xcode
xcodebuild -project build/IRCabie.xcodeproj -configuration Release
```

---

## Project Structure

```text
QWare_IRCabie/
├── Assets/
│   ├── background.bmp
│   ├── knob_vertical_sprites.png
│   ├── toggle_knob_vertical_sprites
│   └── icon.ico
├── Source/
│   ├── PluginProcessor.cpp
│   ├── PluginProcessor.h
│   ├── PluginEditor.cpp
│   ├── PluginEditor.h
│   └── CabinetIRLoader.h
├── CMakeLists.txt
└── README.md
```

## Core Audio Engine

The plugin core includes a dedicated **Cabinet Impulse Response Loader** (`CabinetIRLoader`), utilizing JUCE's `juce::dsp::Convolution` engine to load external stereo or mono `.wav` IR files seamlessly.

## License

Developed by **QWare.id**. Distributed under the [MIT License](LICENSE).