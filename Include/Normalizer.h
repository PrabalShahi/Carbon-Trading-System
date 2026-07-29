#pragma once
#include "MarketTick.h"
#include "NormalizedTick.h"

class Normalizer
{
public:
    NormalizedTick normalize(
        const MarketTick& tick,
        const CurrencyTick& fx);
};
