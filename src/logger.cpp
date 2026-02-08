#include "logger.hpp"

#include <chrono>
#include <ctime>

static std::string now_iso() {
  auto now = std::chrono::system_clock::now();
  std::time_t t = std::chrono::system_clock::to_time_t(now);
  char buf[32];
  std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&t));
  return std::string(buf);
}

Logger::Logger(const std::string& path) : out_(path, std::ios::app) {}

void Logger::info(const std::string& msg) {
  if (out_) {
    out_ << now_iso() << " " << msg << "\n";
    out_.flush();
  }
}
