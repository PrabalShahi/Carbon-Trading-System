#include "Logger.h"

    Logger::Logger()
    {
        EngineFile.open("Logs/Engine.log");
       // RiskFile.open("Logs/RiskManager.log");
        TradeFile.open("Logs/Trade.log");
    }

void Logger::EngineLog(const string& message)
    {
        EngineFile << message <<'\n';
    }

// void Logger::RiskLog(const string& message)
//     {
//         RiskFile << message <<'\n';
//     }

void Logger::TradeLog(const string& message)
    {
        TradeFile << message <<'\n';
    }

    Logger::~Logger()
    {
        if(EngineFile.is_open())
            EngineFile.close();

        // if(RiskFile.is_open())
        //     RiskFile.close();

        if(TradeFile.is_open())
            TradeFile.close();
    }