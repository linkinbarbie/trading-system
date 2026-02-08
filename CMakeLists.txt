cmake_minimum_required(VERSION 3.16)
project(trading_system LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(trading_system
  src/main.cpp
  src/order_book.cpp
  src/market_data.cpp
  src/strategy.cpp
  src/simulator.cpp
  src/logger.cpp
)

target_include_directories(trading_system PRIVATE src)
