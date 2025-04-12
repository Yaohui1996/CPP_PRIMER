#include <algorithm>
#include <cstdint>
#include <iterator>
#include <vector>

#include "spdlog/fmt/bundled/ranges.h"
#include "spdlog/spdlog.h"

int main(int argc, char *args[]) {
  //
  spdlog::set_level(spdlog::level::debug); // Set global log level to debug
  //
  int32_t ia[] = {27, 210, 12, 47, 109, 83};
  SPDLOG_INFO("ia=[{}]", fmt::join(ia, ","));

  const int32_t val = 47;
  SPDLOG_INFO("val={}", val);

  //   yaohui::toolkits::print(val);
  int32_t *result = std::find(std::begin(ia), std::end(ia), val);
  SPDLOG_INFO("result->{}", *result);

  return 0;
}