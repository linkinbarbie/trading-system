#pragma once

#include <string>
#include <vector>

#include "order_book.hpp"

struct MarketUpdate {
  Side side;
  char action; // A=add, M=modify, C=cancel
  double price;
  double qty;
};

class MarketDataParser {
public:
  // format: action,side,price,qty  e.g., A,B,101.25,50
  static std::vector<MarketUpdate> parse_lines(const std::vector<std::string>& lines);
};
