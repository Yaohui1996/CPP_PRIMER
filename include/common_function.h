#ifndef YAOHUI_COMMON_FUNCTION_H
#define YAOHUI_COMMON_FUNCTION_H

#include "Sales_data.h"
#include <cstdint>
#include <string>
#include <vector>

bool isShorter(const std::string &lhs, const std::string &rhs);

void elimDups(std::vector<std::string> &vec);

void elimDups(std::vector<std::int32_t> &vec);

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);

std::string convertToIsbn(const Sales_data &sd);

void biggies(std::vector<std::string> &words, const std::size_t sz);
void biggies_partition(std::vector<std::string> &words, const std::size_t sz);
void biggies_stable_partition(std::vector<std::string> &words, const std::size_t sz);

std::string make_plural(const std::size_t ctr, const std::string &word, const std::string &ending);

bool check_size(const std::string &s, std::string::size_type sz);

#endif // YAOHUI_COMMON_FUNCTION_H