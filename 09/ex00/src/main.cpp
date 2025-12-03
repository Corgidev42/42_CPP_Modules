#include <cstddef>
#include "../include/BitcoinExchange.hpp"
#include <iomanip>
#include <iostream>

void printMap(const std::map<time_t, float>& map){
  for (std::map<time_t, float>::const_iterator it = map.begin(); it != map.end(); ++it){
    std::cout << it->first << " => " << std::fixed << std::setprecision(2) << it->second << std::endl;
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2){
    std::cerr << "Error: could not open file." << std::endl;
    return -1;
  }


  std::map<time_t, float>* btcData = extractBtcData("data.csv");
  if (!btcData){
    return -1;
  }

  processData(argv[1], *btcData);
  delete btcData;
  return 0;
}
