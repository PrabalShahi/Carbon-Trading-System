#include <iostream>
#include "TradeX.h"
#include "FeedHandlerBooks.h"
#include "FeedHandlerCurrency.h"
#include "RiskResult.h"
#include "SpreadTick.h"


using namespace std;


Engine::Engine()
{}

void Engine::Init()
{

 LoadOrderBooks();
 LoadNormalizer();
 LoadSpreadCalculator();
 LoadArbitrageDetector();
 LoadRiskManager();

    logger.EngineLog("Engine is working properly");

}

void Engine::LoadOrderBooks()
{
    cbl = FeedHandlerBooks::readCSV("Data/cbl_market_data.csv");
    pxil =  FeedHandlerBooks::readCSV("Data/pxil_market_data.csv");
    logger.EngineLog("OrderBook Handler is working properly");

    currency = FeedHandlerCurrency::readCurrencyCsv("Data/usd_inr.csv");
    logger.EngineLog("Currency Handler is working properly");

}

void Engine::LoadNormalizer()
{
    NormalizedCbl.clear();
    NormalizedPxil.clear();

    // size_t cblCount = min(cbl.size(), currency.size()); // // For taking minimum size
    if (cbl.size() != currency.size())
    {
        throw runtime_error("CBL and currency data size mismatch");
    } else
    {
        NormalizedCbl.reserve(cbl.size());
        for (size_t i = 0; i < cbl.size(); ++i)
        {
            NormalizedCbl.push_back(
            normalizer.normalize(cbl[i], currency[i]));
        }

        // for (const auto& n : NormalizedCbl)
        // {
        //     cout<<
        //       //  n.timestamp<<"\n"<<
        //         n.bid<<"\n"<<
        //         n.ask<<"\n"<<
        //         n.volume<<"\n";
        // }

        logger.EngineLog("Cbl has been Normalized");
    }


    //  size_t pxilCount = min(pxil.size(), currency.size()); // For taking minimum size
    if (pxil.size() != currency.size())
    {
        throw runtime_error("PXIL and currency data size mismatch");
    } else
    {
        NormalizedPxil.reserve(pxil.size());
        for (size_t i = 0; i < pxil.size(); ++i)
        {
            NormalizedPxil.push_back(
            normalizer.normalize(pxil[i], currency[i]));
        }

        // for (const auto& n : NormalizedPxil)
        // {
        //     cout<<
        //        //   n.timestamp<<"\n"<<
        //         //  n.bid<<"\n"<<
        //           n.ask<<"\n";
        //       //    n.volume<<"\n";
        // }

        logger.EngineLog("Pxil has been Normalized");
    }
}

void Engine::LoadSpreadCalculator()
{
    spreads.clear();
    spreads.reserve(NormalizedCbl.size());

    for (size_t i = 0; i < NormalizedCbl.size(); ++i)
{
    spreads.push_back(
    spreadCalculator.calculate(
        NormalizedCbl[i],
        NormalizedPxil[i]
    )
    );
    }

    // for (const auto& s : spreads)
    // {
    //     cout<<
    //         "Spread: "<<s.spread<<'\n'<<
    //         "cblBid_Volume: "<<s.cblBidVolume<<'\n'<<
    //         "pxilAsk_Volume: "<<s.pxilAskVolume<<'\n'<<
    //             "Min_Volume: "<<s.minVol<<'\n';
    // }

    logger.EngineLog("Spread Calculated");
}

void Engine::LoadArbitrageDetector()
{

    arbitrage.clear();
    arbitrage.reserve(spreads.size());

    for (size_t i = 0; i <spreads.size(); ++i)
    {
        arbitrage.push_back(
        arbitrageDetector.detect(
            spreads[i])
        );

    }

    // for (const auto& a : arbitrage)
    // {
    //     cout<<"Cbl_Bid: "<<a.Cblbid<<"\n"<<
    //         "Pxil_Ask: "<<a.Pxilask<<'\n'<<
    //         "Spread: "<<a.spreadD<<"\n"<<
    //         "cblBid_Volume: "<<a.cblBid_Volume<<"\n"
    //        "pxilAsk_Volume: "<<a.pxilAsk_Volume<<'\n'<<
    //         "Trade_Volume: "<<a.Executable_Volume<<'\n'<<
    //             "Net_Profit: "<<a.Net_Profit<<'\n'<<
    //             //    a.Timestamp<<'\n'<<
    //            "----------------------"<<'\n';
    // }
 //  cout<<arbitrage.size()<<"\n";

    logger.EngineLog("Arbitrage Detected");

}

void Engine::LoadRiskManager()
{

    for (size_t i = 0; i < spreads.size(); ++i)
    {
       // RiskResult risk = riskManager.evaluate(spread);

        if (RiskResult risk = riskManager.evaluate(spreads[i]); risk.Approved)
        {
            // Execute trade
            execution.push_back(
            exec.execute(
                spreads[i]));

            logger.TradeLog("Trade has been Executed");
        }
        else
        {
            logger.TradeLog("Trade has been Declined");
        }
    }

    for (const auto& e : execution)
    {
        cout<<"Volume: "<<e.volume<<'\n'
            <<"Profit: "<<e.profit<<'\n';
    }

    cout<<execution.size()<<'\n';

    logger.EngineLog("Risk Manager is working Properly");
}
