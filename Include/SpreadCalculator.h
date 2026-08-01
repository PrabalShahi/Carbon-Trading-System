#pragma once
#include "NormalizedTick.h"
#include "SpreadTick.h"

using namespace std; // Using this for the time being

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
