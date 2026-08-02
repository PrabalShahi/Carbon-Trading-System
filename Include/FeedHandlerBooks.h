#pragma once
#include<vector>
#include<string>
#include<fstream>
#include "MarketTick.h"

using namespace std; // Using this for the time being

class FeedHandlerBooks
{
private:
 static  vector<string> tokenise(string line, char seperator);


public:
   FeedHandlerBooks();
   static vector<MarketTick> readCSV(string CsvFileName);
  static  MarketTick StringsToMT(const vector<string>& tokens);


};
