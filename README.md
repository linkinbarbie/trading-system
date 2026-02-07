# trading-system

Tiny C++ trading-system demo that runs end-to-end.

## Features
- Order book with add/modify/cancel
- Top-of-book view
- Simple market data parser (CSV-like)
- Basic latency/throughput metrics

## Build (CMake)
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
./trading_system
```

## Run
The binary loads a small set of sample updates and prints top-of-book plus metrics.

## Project Layout
- `src/` C++ sources
- `CMakeLists.txt` build config

## Change Log
- Initial runnable C++ trading-system demo.
