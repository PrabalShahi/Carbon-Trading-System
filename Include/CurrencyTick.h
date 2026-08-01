#pragma once
#include<string>

using namespace std; // Using this for the time being


class CurrencyTick{
public:
    uint64_t timestamps;
    string baseCurrency;
    string quoteCurrency;
    double rate;

    CurrencyTick(uint64_t _timestamps,
              string _baseCurrency,
              string _quoteCurrency,
              double _rate);

};
