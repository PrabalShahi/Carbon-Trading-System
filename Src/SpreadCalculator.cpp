#include "SpreadCalculator.h"
#include <iostream>
#include "NormalizedTick.h"
#include "SpreadTick.h"

SpreadTick SpreadCalculator::calculate(
    const NormalizedTick& cbl,
    const NormalizedTick& pxil)
{
    SpreadTick Spread;

  //  Spread.timestamp = pxil.timestamp;
    Spread.exchangeFee = 30;
    Spread.registryFee = 20;
    Spread.requiredProfit = 50;
    Spread.cblBid  = cbl.bid + 115;  // Added 115 to generate positive spreads
    Spread.pxilAsk = pxil.ask;

    Spread.cblBidVolume = cbl.volume;
    Spread.pxilAskVolume = pxil.volume;
    Spread.Tradeable_Volume = min(Spread.cblBidVolume, Spread.pxilAskVolume); // Minimum Volume we can trade

    Spread.totalCost = (Spread.pxilAsk +  Spread.exchangeFee + Spread.registryFee +  Spread.requiredProfit);
    Spread.spread =  Spread.cblBid - (Spread.pxilAsk +  Spread.exchangeFee + Spread.registryFee +  Spread.requiredProfit);

    Spread.grossProfit = Spread.spread * Spread.Tradeable_Volume;
    Spread.netProfit = Spread.grossProfit - (Spread.exchangeFee + Spread.registryFee);

    return Spread;
}


ArbitrageDetector SpreadCalculator::detect(
        const SpreadTick& spread
    )
{
    ArbitrageDetector detector;

    detector.TotalCost = spread.totalCost;
    detector.Cblbid = spread.cblBid;
    detector.Pxilask = spread.pxilAsk;

 //   detector.Timestamp = spread.timestamp;

    if (detector.Cblbid > detector.TotalCost)
    {
        detector.Pxilask = spread.pxilAsk;
        detector.cblBid_Volume = spread.cblBidVolume;
        detector.pxilAsk_Volume = spread.pxilAskVolume;
        detector.Executable_Volume = spread.Tradeable_Volume;

        detector.spreadD = detector.Cblbid - detector.TotalCost;

        detector.Net_Profit = spread.netProfit;
    }

   return detector;
}




