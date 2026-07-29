#pragma once
#include "NormalizedTick.h"
#include<string>
#include "FeedHandlerCurrency.h"


struct NormalizedTick
{
    uint64_t timestamp;
    std::string exchange;
    double bid;
    double ask;
    int volume;
};