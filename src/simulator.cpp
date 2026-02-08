#include "simulator.hpp"

#include <sstream>

#include "logger.hpp"

Simulator::Simulator(double max_spread) : strategy_(max_spread) {}

SimResult Simulator::run(const std::vector<MarketUpdate>& updates) {
  Logger logger("trades.log");
  SimResult res;

  for (const auto& u : updates) {
    if (u.action == 'A') {
      book_.add(u.side, u.price, u.qty);
    } else if (u.action == 'M') {
      book_.modify(u.side, u.price, u.qty);
    } else if (u.action == 'C') {
      book_.cancel(u.side, u.price);
    }

    res.updates++;

    auto trade = strategy_.on_book_update(book_);
    if (trade) {
      res.trades++;
      std::ostringstream msg;
      msg << "TRADE side=" << (trade->side == Side::Buy ? "B" : "S")
          << " price=" << trade->price
          << " qty=" << trade->qty
          << " top=" << book_.top_of_book_string();
      logger.info(msg.str());
    }
  }

  return res;
}
