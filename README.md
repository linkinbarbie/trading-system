# trading-system

Tiny C++ trading-system demo that runs end-to-end.

## Features
- Order book with add/modify/cancel
- Top-of-book view
- Simple market data parser (CSV-like)
- Basic latency/throughput metrics
- Tiny simulator with a basic strategy
- Trade logging to `trades.log`

## Step-by-Step Setup

### 1) Install CMake and a C++ compiler
On macOS, install Command Line Tools:
```bash
xcode-select --install
```

Check versions:
```bash
cmake --version
g++ --version
```

### 2) Build the project
From the repo root:
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

### 3) Run the demo
```bash
./trading_system
```

Expected output (example):
```
Processed 6 updates in 120 us
Simulated trades: 2
Trades logged to trades.log
```

### 4) Inspect the trade log
```bash
cat trades.log
```

## How It Works (Simple)
1. `MarketDataParser` reads sample CSV updates.
2. `OrderBook` applies add/modify/cancel actions.
3. `Strategy` checks spread and triggers a simulated trade.
4. `Logger` writes trades to `trades.log`.

## Project Layout
- `src/` C++ sources
  - `order_book.*` core order book
  - `market_data.*` CSV parser
  - `strategy.*` basic spread strategy
  - `simulator.*` runs updates + strategy
  - `logger.*` writes `trades.log`
- `CMakeLists.txt` build config

## Troubleshooting
- **`cmake: command not found`**: Install CMake (macOS: `brew install cmake`).
- **`g++: command not found`**: Install Xcode Command Line Tools (`xcode-select --install`).
- **Build fails on old compiler**: Ensure C++17 support (`g++ --version`). If needed, install a newer compiler via Homebrew.
- **No trades in log**: Increase the `max_spread` value in `src/main.cpp` (e.g., `Simulator sim(0.20);`).

## Change Log
- Initial runnable C++ trading-system demo.
