#pragma once

#include <string>
#include <map>
#include <ctime>

std::map<time_t,float>* extractBtcData(const std::string& path);
void processData(char* path, const std::map<time_t, float>& btcData);
