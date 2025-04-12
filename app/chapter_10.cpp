#include <cstdint>
#include <iostream>
#include <vector>

int main(int argc, char *args[]) {
  std::vector<int32_t> a;

  int ia[] = {27, 210, 12, 47, 109, 83};
  for (const auto item : ia) {
    std::cout << item << std::endl;
  }

  return 0;
}