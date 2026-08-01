#include "TradeX.h"
#include <chrono>
#include <iostream>

using namespace std; // Using this for the time being


int main()
{
      // constexpr int num_runs = 10000;
      // long long totalDuration = 0;
      //
      // for (int i = 0; i < num_runs; ++i)
      // {
        auto start = chrono::high_resolution_clock::now();

        Engine e{};
        e.Init();

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Execution Time: " << duration.count() << " microseconds"<<"\n";
      //  totalDuration += duration.count();
     //  }
     //
     // long long avgDuration = totalDuration / num_runs;
     // cout<<"AvgTime: "<<avgDuration<<" microseconds"<<endl;

   return 0;
}
