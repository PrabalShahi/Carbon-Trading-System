#include "FeedHandlerBooks.h"
#include "MarketTick.h"
#include<iostream>

using namespace std; // Using this for the time being

FeedHandlerBooks::FeedHandlerBooks()
= default;

vector<string> FeedHandlerBooks::tokenise(string Line, char separator)
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

vector<MarketTick> FeedHandlerBooks::readCSV(string CsvFileName)
{
    ifstream CsvFile{CsvFileName};
    vector<MarketTick> entries;

    if (CsvFile.is_open())
    {
        string line;
    //    cout<<"File has been Opened"<<"\n";
            while (getline(CsvFile, line))
            {
             //   cout<<"Read Line - "<<line<<"\n";
             MarketTick MT = StringsToMT(tokenise(line, ','));

               entries.push_back(MT);
            }



    } else
    {
        cout<<"Could not open the File"<<"\n";
    }

 return entries;
}

 MarketTick FeedHandlerBooks::StringsToMT(const vector<string>& tokens)
{
    double ask;
    double bid;
    int volume;
    uint64_t timestamps;

    bid = stod(tokens[2]);
    ask = stod(tokens[3]);
    volume = stoi(tokens[4]);
    timestamps = stoi(tokens[0]);

    MarketTick MT{timestamps, tokens[1], bid, ask, volume, tokens[5]};

    return MT;

}
