#pragma once

#include <optional>

#include "order_book.hpp"

struct Trade {
  Side side;
  double price = 0.0;
  double qty = 0.0;
};

class Strategy {
public:
  explicit Strategy(double max_spread) : max_spread_(max_spread) {}

  // Returns a simulated trade when spread is tight enough.
  std::optional<Trade> on_book_update(const OrderBook& book) const;

private:
  double max_spread_ = 0.05;
};
