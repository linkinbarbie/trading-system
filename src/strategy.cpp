#include "strategy.hpp"

std::optional<Trade> Strategy::on_book_update(const OrderBook& book) const {
  auto bid = book.best_bid();
  auto ask = book.best_ask();
  if (!bid || !ask) return std::nullopt;

  double spread = ask->price - bid->price;
  if (spread <= max_spread_) {
    Trade t;
    t.side = Side::Buy;
    t.price = ask->price;
    t.qty = 1.0;
    return t;
  }
  return std::nullopt;
}
