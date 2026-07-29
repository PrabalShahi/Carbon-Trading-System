#include "ExecutionEngine.h"



ExecutionResult ExecutionEngine::execute(
    const SpreadTick& spread
//     const RiskResult& result
     )
{
    ExecutionResult exec;

  //  exec.approved = result.Approved;

    // if ( (exec.approved = true && spread.netProfit > result.minProfit))
    // {
     //   exec.executed = true;
     //   exec.reason = "Everything is working properly";
         exec.volume = spread.Tradeable_Volume;
        exec.profit = spread.netProfit;


   // }
    // else
    // {
    //     exec.executed = false;
    //     exec.reason = "There is a problem";
    // }

    return exec;
}
