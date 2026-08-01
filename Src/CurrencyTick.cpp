#include "CurrencyTick.h"

using namespace std; // Using this for the time being

CurrencyTick::CurrencyTick(uint64_t _timestamps,
           string _baseCurrency,
           string _quoteCurrency,
           double _rate) :
timestamps(_timestamps), baseCurrency(_baseCurrency), quoteCurrency(_quoteCurrency), rate(_rate)
{ }
