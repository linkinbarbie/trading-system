#pragma once

#include <map>
#include <string>
#include <optional>

enum class Side { Buy, Sell };

struct Level {
  double price = 0.0;
  double qty = 0.0;
};

class OrderBook {
public:
  void add(Side side, double price, double qty);
  void modify(Side side, double price, double qty);
  void cancel(Side side, double price);

  std::optional<Level> best_bid() const;
  std::optional<Level> best_ask() const;

  std::string top_of_book_string() const;

private:
  // price -> qty; bids descending, asks ascending
  std::map<double, double, std::greater<double>> bids_;
  std::map<double, double, std::less<double>> asks_;
};
