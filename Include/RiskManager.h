#pragma once
#include "RiskManager.h"
#include "SpreadTick.h"
#include "RiskResult.h"


class RiskManager
{
public:
    RiskResult evaluate(
        const SpreadTick& spread);

};