#include <iostream>
#include <vector>

std::vector<std::vector<int>> max_conv(
    const std::vector<std::vector<int>> &array,
    const std::vector<std::vector<int>> &filter)
{
  int cnt = 0;
  std::vector<std::vector<int>> v;
  int filter_size = filter.size();
  int n = array.size() - filter_size + 1;

  for (int k = 0; k < n; ++k) {
    std::vector<int> calced;
    for (int m = 0; m < n; ++m) {
      int sell = 0;
      for (int i = 0; i < filter_size; ++i) {
        for (int j = 0; j < filter_size; ++j) {
          sell += array.at(k + i).at(m + j) * filter.at(i).at(j);
        }
      }
      calced.push_back(sell);
    }
    v.push_back(calced);
    ++cnt;
    if (cnt == 2){
      for (auto e : calced) {
        std::cout << e << ' ';
      }
      std::cout << '\n';
    }
  }
  return v;
}

int main()
{
  std::vector<std::vector<int>> v = //{{0, 1, 2, 1}, {1, 3, 1, 0}, {3, 2, 0, 0}, {1, 0, 0, 2}};
  {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};
  // {{1, 2, 3, 0},
  //   {0, 1, 2, 3},
  //   {3, 0, 1, 2},
  //   {2, 3, 0, 1}};

  std::vector<std::vector<int>> filter = //{{1, 2, 3}, {1, 0, 1}, {0, 2, 1}};
  {{16, 17, 18}, {19, 20, 21}, {22, 23, 24}};
  // {{2, 0, 1},
  //   {0, 1, 2},
  //   {1, 0, 2}};

  auto ret = max_conv(v, filter);

  for (auto row : ret) {
    for (auto cell : row) {
      std::cout << cell << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
