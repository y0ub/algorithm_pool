#include <iostream>
#include <vector>

std::vector<int> decimal_to_binary(int value)
{
  std::vector<int> v(4);
  for (int i = 0; i < 4; ++i) {
    v.at(3 - i) = value % 2;
    value /= 2;
  }
  return v;
}

void binary_coded_decimal(int value)
{
  std::vector<int> digit;
  // pick value every digit
  // and push order by small digit
  while (value > 0) {
    digit.push_back(value % 10);
    value /= 10;
  }
  int n = digit.size();
  for (int i = 0; i < n; ++i) {
    std::vector<int> v = decimal_to_binary(digit.at(n - 1 - i) % 10);
    for (int i = 0; i < v.size(); ++i) {
      std::cout << v.at(i);
    }
  }
}

int main()
{
  int value;
  std::cin >> value;
  binary_coded_decimal(value);
}
