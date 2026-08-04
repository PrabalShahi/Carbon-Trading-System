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
git clone https://github.com/nitro-png/Cplus__Trading_System_Sim.git

cd Cplus__Trading_System_Sim

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

This project uses carbon credit market data — CBL (priced in USD) and PXIL (priced in INR) — as a realistic, domain-grounded test case for the trading engine. It's worth being explicit about what that does and doesn't mean.

CBL's VCU and PXIL's CCC are not the same instrument. CBL trades Verified Carbon Units (VCUs) under the voluntary carbon market (e.g. Verra). PXIL trades Carbon Credit Certificates (CCCs) under India's Carbon Credit Trading Scheme (CCTS), a domestic compliance market for obligated industrial entities. Different registries, different verification standards, different regulatory regimes. A price gap between them isn't necessarily an inefficiency — it can just be two different products, correctly priced differently. The arbitrage detector here demonstrates the mechanism (comparing spreads across normalized, currency-converted feeds), not a claim that this specific cross-market trade is actually executable.

Settlement, not latency, is the real bottleneck in carbon markets. A carbon credit trade settles through a registry transfer, which takes hours to days — not milliseconds. So the low-latency work in this project (ring buffers, memory pools, eventually CUDA) is a systems-engineering exercise in its own right, not something this particular market inherently demands. The skills transfer to markets where latency is the bottleneck (equities, FX, crypto); carbon just isn't one of them yet.

CCTS does not currently permit short selling (Phase 1). That rules out one leg of a classic two-sided arbitrage on the domestic side as the scheme is presently designed.

Cross-border capital movement between an INR-denominated Indian exchange and a USD-denominated global exchange carries real regulatory considerations (FEMA/RBI) that this project doesn't attempt to solve.

In short: this is trading infrastructure — feed handling, normalization, spread calculation, and low-latency execution mechanics — built and tested against a realistic cross-market scenario, not a claim of a live, tradeable strategy.
