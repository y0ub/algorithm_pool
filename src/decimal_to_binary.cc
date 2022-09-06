#include <iostream>
#include <vector>

int main()
{
  int decimal = 32 + 0 + 8 + 0 + 2 + 1; // 43 -> 101011
  std::vector<int> binary;

  while (decimal != 0) {
    binary.push_back(decimal % 2);
    decimal /= 2;
  }

  std::reverse_iterator<std::vector<int>::iterator> begin(binary.end());
  std::reverse_iterator<std::vector<int>::iterator> end(binary.begin());

  std::for_each(begin, end, [](auto e){std::cout << e;});
  
  return 0;
}
