#pragma once
#include "NormalizedTick.h"
#include "SpreadTick.h"

using namespace std;

class SpreadCalculator
{

public:
    SpreadTick calculate(
        const NormalizedTick& cbl,
        const NormalizedTick& pxil);

    ArbitrageDetector detect(
    const SpreadTick& spread
    );
};