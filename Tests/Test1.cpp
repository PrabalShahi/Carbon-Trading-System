// #include <catch2/catch_test_macros.hpp>
// #include <catch2/matchers/catch_matchers_floating_point.hpp>
// #include "Normalizer.h"
// #include "MarketTick.h"
// #include "CurrencyTick.h"
//
// TEST_CASE("Normalizer::normalize core logic verification", "[normalizer]") {
//     Normalizer normalizer;
//
//     // 1. Properly construct CurrencyTick using its 4-argument constructor:
//     // CurrencyTick(timestamp, baseCurrency, quoteCurrency, rate)
//     CurrencyTick fx(1718223900000, "USD", "INR", 0.92);
//
//     SECTION("Applies FX rate conversions when currency is USD") {
//         // 2. Properly construct MarketTick using its 6-argument constructor:
//         // MarketTick(timestamp, exchange, bid, ask, volume, currency)
//         // Fixed volume to be an integer (1) to match your 'int' definition
//         MarketTick inputTick(1718223900000, "CBL", 100.0, 105.0, 1, "USD");
//
//         // Run the normalizer calculation
//         NormalizedTick result = normalizer.normalize(inputTick, fx);
//
//         // Core assertions
//         CHECK(result.timestamp == 1718223900000);
//         CHECK(result.exchange == "CBL");
//         CHECK(result.volume == 1);
//
//         // Verify math transformations (100.0 * 0.92 = 92.0)
//         REQUIRE_THAT(result.bid, Catch::Matchers::WithinRel(92.0, 0.0001));
//         REQUIRE_THAT(result.ask, Catch::Matchers::WithinRel(96.6, 0.0001));
//     }
//
//     SECTION("Passes prices through unchanged when currency is not USD") {
//         // 3. Create a non-USD market tick using the constructor
//         MarketTick inputTick(1718224000000, "Pxil", 100.0, 105.0, 2, "INR");
//
//         // Run the normalizer calculation
//         NormalizedTick result = normalizer.normalize(inputTick, fx);
//
//         // Verify prices were NOT modified by the FX rate
//         REQUIRE(result.bid == 100.0);
//         REQUIRE(result.ask == 105.0);
//     }
// }

// #include <fstream>
// #include <string>
// #include <iostream>
// #include <filesystem>
//
// class logger
// {
// private:
//     std::ofstream file;
//
// public:
//     logger();
//     ~logger();
//
//     void log(const std::string& message);
// };
//
//  logger::logger()
// {
//     file.open("Test1.log", std::ios::app);
// }
//
//  logger::~logger()
// {
//     if (file.is_open())
//     {
//         file.close();
//     }
// }
//
//
// void logger::log(const std::string& message)
// {
//     file<<message<<"\n";
// }
//
// int main()
// {
//     logger load;
//    //  std::cout << std::filesystem::current_path() << '\n';
//     load.log("passed");
//
//      return 0;
// }