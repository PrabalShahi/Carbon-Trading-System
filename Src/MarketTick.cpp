#include "MarketTick.h"

using namespace std;

MarketTick::MarketTick(uint64_t _timestamps,
             string _exchange,
             double _bid,
            double _ask,
            int _volume,
            string _currency) :
bid(_bid), ask(_ask), volume(_volume), timestamp(_timestamps),
currency(_currency), exchange(_exchange)
{ }

