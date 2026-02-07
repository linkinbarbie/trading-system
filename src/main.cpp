#include "order_book.hpp"
#include "market_data.hpp"

#include <chrono>
#include <iostream>

int main() {
  OrderBook book;

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
  for (const auto& u : updates) {
    if (u.action == 'A') {
      book.add(u.side, u.price, u.qty);
    } else if (u.action == 'M') {
      book.modify(u.side, u.price, u.qty);
    } else if (u.action == 'C') {
      book.cancel(u.side, u.price);
    }
  }
  auto end = std::chrono::high_resolution_clock::now();

  auto elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

  std::cout << "Top of Book: " << book.top_of_book_string() << "\n";
  std::cout << "Processed " << updates.size() << " updates in " << elapsed_us << " us\n";
  return 0;
}
