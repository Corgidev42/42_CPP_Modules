#include "../include/BitcoinExchange.hpp"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

static bool parseDate(const std::string& str, std::tm& t)
{
  int year, month, day;
  if (sscanf(str.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
    return false;
  t.tm_year = year - 1900;
  t.tm_mon = month - 1;
  t.tm_mday = day;
  t.tm_hour = 0;
  t.tm_min = 0;
  t.tm_sec = 0;
  t.tm_isdst = -1;
  return true;
}

std::map<time_t,float>* extractBtcData(const std::string& path){
  std::ifstream file(path.c_str());
  if (!file.good()){
    std::cerr << "can't open file : data.csv" << std::endl;
    return NULL;
  }

  std::tm t;
  float value;
  time_t timestamp;

  std::map<time_t, float>* btcData = new std::map<time_t, float>();
  if (!btcData){
    std::cerr << "failed allocated memory" << std::endl;
    return NULL;
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)){
    size_t pos = line.find(',');
    if (pos == std::string::npos)
      break;
    std::string dateStr = line.substr(0, pos);
    std::istringstream iss(line.substr(pos + 1));
    if (!(iss >> value))
      break;
    std::memset(&t, 0, sizeof(t));
    if (!parseDate(dateStr, t))
      break;
    timestamp = std::mktime(&t);
    btcData->insert(std::pair<time_t, float>(timestamp, value));
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
    if (line.size() < 10){
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    std::string dateStr = line.substr(0, 10);
    std::tm t;
    std::memset(&t, 0, sizeof(t));
    if (!parseDate(dateStr, t)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    if (line.size() < 12 || line[10] != ' ' || line[11] != '|'){
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    float rate = -1;
    std::istringstream l(line.substr(12));
    if (!(l >> rate)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    time_t timestamp;
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
   }

  return ;
}
