#include "order_book.hpp"

#include <sstream>

void OrderBook::add(Side side, double price, double qty) {
  if (side == Side::Buy) {
    bids_[price] += qty;
  } else {
    asks_[price] += qty;
  }
}

void OrderBook::modify(Side side, double price, double qty) {
  if (side == Side::Buy) {
    if (qty <= 0.0) {
      bids_.erase(price);
    } else {
      bids_[price] = qty;
    }
  } else {
    if (qty <= 0.0) {
      asks_.erase(price);
    } else {
      asks_[price] = qty;
    }
  }
}

void OrderBook::cancel(Side side, double price) {
  if (side == Side::Buy) {
    bids_.erase(price);
  } else {
    asks_.erase(price);
  }
}

std::optional<Level> OrderBook::best_bid() const {
  if (bids_.empty()) return std::nullopt;
  auto it = bids_.begin();
  return Level{it->first, it->second};
}

std::optional<Level> OrderBook::best_ask() const {
  if (asks_.empty()) return std::nullopt;
  auto it = asks_.begin();
  return Level{it->first, it->second};
}

std::string OrderBook::top_of_book_string() const {
  std::ostringstream out;
  auto bid = best_bid();
  auto ask = best_ask();

  out << "BID ";
  if (bid) {
    out << bid->price << " x " << bid->qty;
  } else {
    out << "(none)";
  }
  out << " | ASK ";
  if (ask) {
    out << ask->price << " x " << ask->qty;
  } else {
    out << "(none)";
  }
  return out.str();
}
