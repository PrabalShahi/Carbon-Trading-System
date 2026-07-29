#pragma once
#include<string>

using namespace std;

class MarketTick{
public:
    uint64_t timestamp;
    string exchange;
     double bid;
     double ask;
      int volume;
     string currency;


MarketTick(uint64_t _timestamps,
             string _exchange,
             double _bid,
            double _ask,
             int _volume,
            string _currency);

};
