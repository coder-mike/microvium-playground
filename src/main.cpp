#include <iostream>
#include <fstream>
#include <stdexcept>
#include "App_ffi.h"

std::vector<uint8_t> readFile(const std::string& filename);

int main() {
  App app(readFile("../src/generated/snapshot.mvm-bc"));
  app.command("fib", app.newNumber(100));
  return 0;
}

std::string App::intToString(int32_t val) {
  return std::to_string(val);
}

std::string App::floatToString(double val) {
  return std::to_string(val);
}

void App::floatLog(double val) {
  std::cout << val << std::endl;
}

void App::stringLog(std::string val) {
  std::cout << val << std::endl;
}

void App::emitAck(std::string command) {
  std::cout << "Ack: " << command << std::endl;
}

void App::emitError(std::string command, std::string err) {
  std::cout << "Error: " << command << ":" << err << std::endl;
}

std::vector<uint8_t> readFile(const std::string& filename) {
  std::ifstream instream(filename, std::ios::in | std::ios::binary);
  if (!instream.good()) {
    throw std::invalid_argument("Could not open file");
  }
  std::vector<uint8_t> data((std::istreambuf_iterator<char>(instream)), std::istreambuf_iterator<char>());
  return data;
}