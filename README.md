# Carbon Trading System

A modular **Modern C++ trading system simulator** for carbon market trading. The project processes historical market data, detects arbitrage opportunities, performs risk validation, executes simulated trades, and logs trading activity. It is designed as a foundation for a high-performance trading engine.

---

## Repository

**GitHub:** https://github.com/nitro-png/Cplus__Trading_System_Sim

---

## Features

- Market data ingestion from CSV files
- Market data feed normalization
- Currency normalization
- Spread calculation
- Arbitrage detection
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
├── Tests/
├── CMakeLists.txt
├── Final_Design.jpeg
└── README.md
```

---

## Technologies

- C++17
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
