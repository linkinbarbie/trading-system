#include "market_data.hpp"

#include <sstream>

static Side parse_side(const std::string& s) {
  return (s == "B") ? Side::Buy : Side::Sell;
}

std::vector<MarketUpdate> MarketDataParser::parse_lines(const std::vector<std::string>& lines) {
  std::vector<MarketUpdate> out;
  for (const auto& line : lines) {
    std::istringstream ss(line);
    std::string action, side, price, qty;

    if (!std::getline(ss, action, ',')) continue;
    if (!std::getline(ss, side, ',')) continue;
    if (!std::getline(ss, price, ',')) continue;
    if (!std::getline(ss, qty, ',')) continue;

    MarketUpdate u;
    u.action = action.empty() ? 'A' : action[0];
    u.side = parse_side(side);
    u.price = std::stod(price);
    u.qty = std::stod(qty);
    out.push_back(u);
  }
  return out;
}
