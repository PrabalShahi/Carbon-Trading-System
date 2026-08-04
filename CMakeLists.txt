cmake_minimum_required(VERSION 3.20)
project(CarbonTradingSystem)

set(CMAKE_CXX_STANDARD 20)


add_executable(CarbonTradingSystem
        Src/Main.cpp
        Src/TradeX.cpp
        Src/FeedHandlerBooks.cpp
        Src/FeedHandlerCurrency.cpp
        Src/MarketTick.cpp
        Src/CurrencyTick.cpp
        Src/Normalizer.cpp
        Src/SpreadCalculator.cpp
        Src/Logger.cpp
        Src/RiskManager.cpp
        Src/ExecutionEngine.cpp
        Src/FSM.cpp
)

 target_include_directories(CarbonTradingSystem PRIVATE Include)

#find_package(Catch2 3 REQUIRED)
#add_executable(run_project_tests
#        Tests/Test1.cpp
#        Src/Normalizer.cpp
#        Src/MarketTick.cpp
#        src/CurrencyTick.cpp
#)
# target_include_directories(run_project_tests PRIVATE Include)
#target_link_libraries(run_project_tests PRIVATE Catch2::Catch2WithMain)
