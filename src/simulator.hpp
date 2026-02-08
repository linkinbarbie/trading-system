#pragma once

#include <vector>

#include "market_data.hpp"
#include "order_book.hpp"
#include "strategy.hpp"

struct SimResult {
  int updates = 0;
  int trades = 0;
};

class Simulator {
public:
  Simulator(double max_spread);

  SimResult run(const std::vector<MarketUpdate>& updates);

private:
  OrderBook book_;
  Strategy strategy_;
};
