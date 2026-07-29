#include "FeedHandlerCurrency.h"
#include<iostream>

using namespace std;

FeedHandlerCurrency::FeedHandlerCurrency()
= default;

vector<string> FeedHandlerCurrency::tokeniseCurrency(string Line, char separator)
{
    vector<string> tokens;
    signed int end;
    string token;

    signed int start = Line.find_first_not_of(separator, 0);

    do
    {
        end = Line.find_first_of(separator, start);

        if (start == Line.length() || start == end) break;

        if (end >= 0)
        {
            token = Line.substr(start, end - start);
        }
        else
        {
            token = Line.substr(start, Line.length() - start);
        }

        tokens.push_back(token);
        start = end + 1;

    } while (end > 0);
    return tokens;
}

vector<CurrencyTick> FeedHandlerCurrency::readCurrencyCsv(string CsvFileName)
{
    ifstream CsvFile{CsvFileName};
    vector<CurrencyTick> entries;

    if (CsvFile.is_open())
    {
        string line;
       // cout<<"File has been Opened"<<"\n";
        while (getline(CsvFile, line))
        {
         //   cout<<"Read Line - "<<line<<"\n";
            CurrencyTick CU = StringsToCurr(tokeniseCurrency(line, ','));

            entries.push_back(CU);
        }


    } else
    {
        cout<<"Could not open the File"<<"\n";
    }
    return entries;
}

CurrencyTick FeedHandlerCurrency::StringsToCurr( vector<string> tokens)
{
    double rate;
    uint64_t timestamps;

    rate = stod(tokens[3]);
    timestamps = stoi(tokens[0]);

    CurrencyTick CU{timestamps, tokens[1], tokens[2], rate};
    return CU;

}