#pragma once
#include<vector>
#include "MarketTick.h"
#include "CurrencyTick.h"
#include "ExecutionEngine.h"
#include "ExecutionResult.h"
#include "Logger.h"
#include "NormalizedTick.h"
#include "Normalizer.h"
#include "RiskManager.h"
#include "RiskResult.h"
#include "SpreadCalculator.h"
#include "SpreadTick.h"

using namespace std;


class Engine{

    Logger logger;
    void LoadOrderBooks();
    void LoadNormalizer();
    void LoadSpreadCalculator();
    void LoadArbitrageDetector();
    void LoadRiskManager();

    vector<MarketTick> pxil;
    vector<MarketTick> cbl;

    vector<CurrencyTick> currency;

    vector<NormalizedTick> NormalizedCbl;
    vector<NormalizedTick> NormalizedPxil;
    Normalizer normalizer;

    vector<SpreadTick> spreads;
    SpreadCalculator spreadCalculator;

    vector<ArbitrageDetector> arbitrage;
    SpreadCalculator arbitrageDetector;

    RiskManager riskManager;

    vector<ExecutionResult> execution;
    ExecutionEngine exec;

public:
    Engine();
  void Init();

};
