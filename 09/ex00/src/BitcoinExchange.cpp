#include "../include/BitcoinExchange.hpp"
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

std::map<time_t,float>* extractBtcData(const std::string& path){
  std::ifstream file(path);
  if (!file.good()){
    std::cerr << "can't open file : data.csv" << std::endl;
    return NULL;
  }

  std::tm t = {};
  float value;
  time_t timestamp;

  std::map<time_t, float>* btcData = new std::map<time_t, float>();
  if (!btcData){
    std::cerr << "failed allocated memory" << std::endl;
    return NULL;
  }

  file.ignore(1000, '\n');
  while (file >> std::get_time(&t, "%Y-%m-%d")){

    file.ignore();
    file >> value;

    timestamp = std::mktime(&t);
    btcData->insert(std::pair<time_t, float>(timestamp, value));
    t.tm_isdst = -1;
  }

  return btcData;
}

void processData(char* path, const std::map<time_t, float>& btcData){
  (void) path;
  (void) btcData;

  std::ifstream file(path);
  if (!file.good()){
    std::cerr << "can't open input file : " << path << std::endl;
    return;
  }
  file.ignore(1000, '\n');
  std::string line;
  while(std::getline(file, line)){
    std::istringstream l(line);
    std::tm t = {};
    float rate = -1;
    time_t timestamp;

    if (!(l >> std::get_time(&t, "%Y-%m-%d"))) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    l.ignore(1);
    if (t.tm_mday == 0 || l.peek() != '|'){
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    l.ignore(2);
    if (!(l >> rate)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    if (rate < 0){
      std::cerr << "Error: not a positive number." << std::endl;
      continue;
    }
    else if (rate > 1000){
      std::cerr << "Error: too large a number."  << std::endl;
      continue;
    }

    timestamp = std::mktime(&t);
    std::map<time_t, float>::const_iterator it = btcData.lower_bound(timestamp);
    if (it == btcData.begin() && (it == btcData.end() || it->first > timestamp)) {
      std::cerr << "Error: no rate available for date => " << line.substr(0, 10) << std::endl;
      continue;
    }
    if (it == btcData.end() || it->first > timestamp)
      --it;
    float result = rate * it->second;
    std::cout << line.substr(0, 10) << " => " << rate << " = " << result << std::endl;

    t.tm_isdst = -1;
   }

  return ;
}
