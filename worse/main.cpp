#include "array.hpp"

int main() {
  worse::array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
  worse::array<int, 6> arr2 = { 1, 2, 3, 4, 5, 6 };
  worse::array<std::string, 3> arr3 = {"this", "is", "array"};

  std::cout << arr1[0] << " 1 \n";
  std::cout << arr1.front() << " 2 \n";

  std::cout << arr3[2] << " 3 \n";
  std::cout << arr3.back() << " 4 \n";


  return 0;
}
