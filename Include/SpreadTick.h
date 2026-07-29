#pragma once

struct SpreadTick
{
  //  uint64_t timestamp;
    double cblBid;
    double pxilAsk;
    double spread;
    int    cblBidVolume;
    int    pxilAskVolume;
    int Tradeable_Volume;

    double exchangeFee;
    double registryFee;
    double requiredProfit;

    double totalCost;
    double grossProfit;
    double netProfit;
};

struct ArbitrageDetector
{
    // uint64_t Timestamp = 0;
    double Cblbid = 0.0;
    double Pxilask = 0.0;

    int cblBid_Volume = 0;
    int pxilAsk_Volume = 0;
    int Executable_Volume = 0;

 //   double spread;
    double TotalCost = 0.0;
    double spreadD = 0.0; // Initializing it to avoid garbage values

    double Net_Profit = 0.0;

};