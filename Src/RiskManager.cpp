#include "RiskResult.h"
#include "RiskManager.h"


RiskResult RiskManager::evaluate(
    const SpreadTick& spread)
{
    RiskResult result;

    result.minProfit = spread.totalCost;

    if (spread.netProfit < result.minProfit)
    {
        result.Approved = false;
        result.reason = "Profit is too low";
    }
    else
    {
        result.Approved= true;
        result.reason = "Approved";
    }

    return result;
}