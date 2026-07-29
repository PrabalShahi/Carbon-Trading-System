#pragma once
#include <fstream>
#include <string>

    using namespace std;

    class Logger
    {
    private:
        ofstream EngineFile, RiskFile, TradeFile;


    public:
        Logger();
        ~Logger();

        void EngineLog(const string& message);
        void TradeLog(const string& message);

    };