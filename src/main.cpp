#include "market_data.hpp"
#include "simulator.hpp"

#include <chrono>
#include <iostream>

int main() {
  std::vector<std::string> sample = {
      "A,B,101.25,50",
      "A,S,101.40,40",
      "A,B,101.20,30",
      "M,B,101.25,60",
      "C,S,101.40,0",
      "A,S,101.35,25",
  };

  auto start = std::chrono::high_resolution_clock::now();
  auto updates = MarketDataParser::parse_lines(sample);
  Simulator sim(0.10);
  auto result = sim.run(updates);
  auto end = std::chrono::high_resolution_clock::now();

  auto elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

  std::cout << "Processed " << updates.size() << " updates in " << elapsed_us << " us\n";
  std::cout << "Simulated trades: " << result.trades << "\n";
  std::cout << "Trades logged to trades.log\n";
  return 0;
}
