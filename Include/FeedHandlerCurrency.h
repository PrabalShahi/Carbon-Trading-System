#pragma once
#include<vector>
#include<string>
#include<fstream>
#include "CurrencyTick.h"


class FeedHandlerCurrency
{

private:
    static  vector<string> tokeniseCurrency(string Line, char separator);

public:
    FeedHandlerCurrency();
    static vector<CurrencyTick> readCurrencyCsv(string CsvFileName);
    static  CurrencyTick StringsToCurr(const vector<string>& tokens);

};
