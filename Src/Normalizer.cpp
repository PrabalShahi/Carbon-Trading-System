#include"Normalizer.h"
#include "NormalizedTick.h"

NormalizedTick Normalizer::normalize(
    const MarketTick& tick,
    const CurrencyTick& fx)
{
   NormalizedTick normalized;

    normalized.timestamp =  tick.timestamp;

    normalized.exchange = tick.exchange;

    normalized.volume = tick.volume;

    if (tick.currency == "USD")
    {
        normalized.bid = tick.bid * fx.rate;
        normalized.ask = tick.ask * fx.rate;
    }
    else
    {
        normalized.bid = tick.bid;
        normalized.ask = tick.ask;
    }

    return normalized;
}
