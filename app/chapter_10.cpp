#include <algorithm>
#include <cstdint>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

#include "spdlog/fmt/bundled/format.h"
#include "spdlog/fmt/bundled/ranges.h"
#include "spdlog/spdlog.h"

void draft() {
  SPDLOG_INFO("\n---------- draft ----------");
  //
  int32_t ia[] = {27, 210, 12, 47, 109, 83};
  SPDLOG_INFO("ia=[{}]", fmt::join(ia, ","));

  const int32_t val = 47;
  SPDLOG_INFO("val={}", val);

  int32_t *result = std::find(std::begin(ia), std::end(ia), val);
  SPDLOG_INFO("result->{}", *result);

  std::list<std::string> list = {"27", "210", "12", "47", "109", "83"};
  SPDLOG_INFO("i={}", fmt::format("{}", list));

  const std::string val_str = "47";
  SPDLOG_INFO("val_str={}", val_str);

  const auto result2 = std::find(list.cbegin(), list.cend(), val_str);
  SPDLOG_INFO("result2->{}", *result2);
}

void func_10_1() {
  SPDLOG_INFO("\n---------- func_10_1 ----------");
  const std::vector<int32_t> a = {1, 1, 2, 2, 2, 3};
  SPDLOG_INFO("a: {}", fmt::format("{}", a));
  const std::int32_t val = 2;
  const auto result = std::count(a.cbegin(), a.cend(), val);
  SPDLOG_INFO("the count of {} in the vector a is: {}", val, result);
}

void func_10_2() {
  SPDLOG_INFO("\n---------- func_10_2 ----------");
  const std::vector<std::string> a = {"1", "1", "2", "2", "2", "3"};
  SPDLOG_INFO("a: {}", fmt::format("{}", a));
  const std::string val = "2";
  const auto result = std::count(a.cbegin(), a.cend(), val);
  SPDLOG_INFO("the count of {} in the vector a is: {}", val, result);
}

void func_10_3() {
  SPDLOG_INFO("\n---------- func_10_3 ----------");
  const std::vector<int32_t> a = {1, 1, 2, 2, 2, 3};
  SPDLOG_INFO("a: {}", fmt::format("{}", a));
  const auto result = std::accumulate(a.cbegin(), a.cend(), 0);
  SPDLOG_INFO("the sum of a is: {}", result);
}

void func_10_6() {
  SPDLOG_INFO("\n---------- func_10_6 ----------");
  std::vector<int32_t> a = {1, 1, 2, 2, 2, 3};
  SPDLOG_INFO("before a: {}", fmt::format("{}", a));
  //
  std::fill_n(a.begin(), a.size(), 0);
  SPDLOG_INFO("after a: {}", fmt::format("{}", a));
}

void func_10_7() {
  SPDLOG_INFO("\n---------- func_10_7 ----------");
  std::list<int32_t> a = {1, 1, 2, 2, 2, 3};
  std::vector<int32_t> b;
  SPDLOG_INFO("before a: {}", fmt::format("{}", a));
  SPDLOG_INFO("before b: {}", fmt::format("{}", b));
  //
  std::copy(a.cbegin(), a.cend(), std::back_inserter(b));
  SPDLOG_INFO("after a: {}", fmt::format("{}", a));
  SPDLOG_INFO("after b: {}", fmt::format("{}", b));
  //
  std::vector<int32_t> c;
  //   c.reserve(10);
  c.resize(10);
  std::fill_n(c.begin(), 10, 0);
  SPDLOG_INFO("c: {}", fmt::format("{}", c));
}

int main(int argc, char *args[]) {
  //
  spdlog::set_level(spdlog::level::debug); // Set global log level to debug

  draft();
  func_10_1();
  func_10_2();
  func_10_3();
  func_10_6();
  func_10_7();

  return 0;
}