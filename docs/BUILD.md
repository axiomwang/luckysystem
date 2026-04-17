# Build Guide (CMake + Ninja)

## Why CMake

This project uses CMake as the canonical build system for:

- Better IDE/tooling support
- Cleaner cross-platform configuration
- Reliable out-of-source builds

## Quick Start

From repository root:

```bash
cmake --preset ninja-debug
cmake --build --preset build-debug
```

Run on macOS:

```bash
./build/debug/LuckySystem.app/Contents/MacOS/LuckySystem
```

## Manual Build Commands

```bash
cmake -S . -B build/debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build/debug
```

## Release Build

```bash
cmake --preset ninja-release
cmake --build --preset build-release
```

## Cleaning

```bash
rm -rf build/
```

If older qmake artifacts exist in source root, remove them once:

```bash
rm -rf *.app Makefile .qmake.stash moc_*.cpp moc_*.o ui_*.h *.o
```

## Qt Discovery

If Qt is not found automatically:

```bash
cmake -S . -B build/debug -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_PREFIX_PATH=/path/to/Qt/lib/cmake
```

## Platform Notes

- Windows: `.xlsx` import is available via ActiveX.
- macOS/Linux: `.xlsx` import path is compiled out and returns failure; use `.csv`/`.txt`.
