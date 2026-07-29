#pragma once
#include "ExecutionResult.h"
#include "RiskManager.h"
#include "SpreadTick.h"

class ExecutionEngine
{
public:

    ExecutionResult execute(
        const SpreadTick& spread
      //  const RiskResult& result
        );

};
