# LuckySystem (Qt C++)

LuckySystem is a Qt Widgets desktop app for name calling / raffle workflows.

This repository now uses CMake + Ninja as the primary build system.

## Requirements

- CMake 3.21+
- Ninja
- Qt 6 (Core, Gui, Widgets)
- A C++17 compiler

On macOS with Homebrew:

```bash
brew install cmake ninja qt
```

## Build (Out-of-Source Only)

In-source builds are intentionally blocked.

### Option 1: CMake Presets (recommended)

Configure Debug:

```bash
cmake --preset ninja-debug
```

Build Debug:

```bash
cmake --build --preset build-debug
```

Configure Release:

```bash
cmake --preset ninja-release
```

Build Release:

```bash
cmake --build --preset build-release
```

### Option 2: Manual CMake + Ninja

```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

## Run

From a build directory:

```bash
# macOS bundle executable
./build/debug/LuckySystem.app/Contents/MacOS/LuckySystem
```

or (if generated as a plain executable on your platform):

```bash
./build/debug/LuckySystem
```

## Project Layout

- UI forms: `*.ui`
- UI windows/controllers: `*interface.*`, `*setting.*`, `widget.*`
- Data model: `person.*`, `personlistmanager.*`
- Raffle strategy base: `rafflemode.*`

## Notes About Platform Behavior

- Excel import uses ActiveX (`QAxObject`) only on Windows.
- On non-Windows platforms, `.xlsx` import currently returns `false` by design.
- `.txt` and `.csv` import are cross-platform.

## Bug Fixes Included In This Revision

- Migrated build to CMake + Ninja.
- Enforced out-of-source builds.
- Fixed link-time virtual method issues in raffle and name interface classes.
- Fixed Qt 6 compatibility (`QTextStream` codec usage removal).
- Guarded Windows-only ActiveX code paths.
- Fixed `.xlsx` extension detection in file import routing.

## Troubleshooting

- If CMake cannot find Qt, provide `CMAKE_PREFIX_PATH`:

```bash
cmake -S . -B build -G Ninja -DCMAKE_PREFIX_PATH=/path/to/Qt/lib/cmake
```

- If you previously built with qmake in the source tree, clean generated files first or use a fresh clone.

## Legacy Build System

- `LuckySystem.pro` is kept for reference only.
- Use CMake + Ninja for ongoing development.