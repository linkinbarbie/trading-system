#pragma once

#include <fstream>
#include <string>

class Logger {
public:
  explicit Logger(const std::string& path);
  void info(const std::string& msg);

private:
  std::ofstream out_;
};
