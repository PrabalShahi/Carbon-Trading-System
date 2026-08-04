# Carbon Trading System

A modular **C++ trading system simulator** for carbon market trading. The project processes simulated market data, detects arbitrage opportunities, performs risk validation, executes simulated trades, and logs trading activity.
It is currently under active development. New features and architectural improvements are being added as I continue learning about low-latency trading systems.

---

## Repository

**GitHub:** https://github.com/PrabalShahi/Carbon-Trading-System

---

## Features

- Market data ingestion from CSV files
- Market data feed normalization
- Currency normalization
- Spread calculation
- Arbitrage detection(cross-exchange comparison)
- Risk management
- Simulated trade execution
- Logging

---

## Current Architecture

```text
Feed Handlers
      │
      ▼
Normalizer
      │
      ▼
Spread Calculator
      │
      ▼
Arbitrage Detector
      │
      ▼
Risk Manager
      │
      ▼
Execution Engine
      │
      ▼
   Logger
```
## Final Architecture

<img width="10238" height="2976" alt="Final_Design" src="https://github.com/user-attachments/assets/2085680d-49d7-4f6a-a68b-afdd1fad4c9b" />


---

## Project Structure

```text
├── Include/
├── Src/
├── Data/
├── Logs/
├── Tests/
├── CMakeLists.txt
├── Final_Design.jpeg
└── README.md
```

---

## Technologies

- C++
- STL
- CMake
- Object-Oriented Programming
- CSV Data Parsing

---

## Build

```bash
git clone https://github.com/PrabalShahi/Carbon-Trading-System.git

cd Carbon-Trading-System

cmake -B build

cmake --build build
```

---

## Roadmap

The current version is a functional prototype. Future versions will include:

Version 2.0
--------------------------
Finite State Machine,
 Ring Buffer,
 Producer / Consumer

Version 3.0
--------------------------
Data-Oriented Design,
 Structure of Arrays,
 SIMD,
 Memory Pool

Version 4.0
--------------------------
NUMA,
 Thread Affinity,
 CUDA
 
--------------------------
A Note on Market Realism

CBL (USD, VCUs) and PXIL (INR, CCCs) are used here as a realistic test case for the trading engine — not a claim that this specific arbitrage is actually executable.

Different instruments: CBL and PXIL trade under different registries/standards; a price gap may reflect that, not inefficiency.
Real bottleneck: Trade matching is already fast on both exchanges — it's cross-registry credit transfer (hours–days) that's slow, not execution.
Carbon HFT is real — but on CME/ICE futures (GEO, EUA), not this spot cross-exchange setup.
CCTS bans short selling (Phase 1), killing one leg of the arbitrage domestically.
Cross-border INR/USD flows carry FEMA/RBI constraints not addressed here..

In short: this is trading infrastructure — feed handling, normalization, spread calculation, and low-latency execution mechanics — built and tested against a realistic cross-market scenario, not a claim of a live, tradeable strategy. The skills demonstrated here transfer directly to markets, including parts of the carbon space, where electronic, low-latency trading is already real.
