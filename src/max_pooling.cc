#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> max_pooling(
    const std::vector<std::vector<int>> &v)
{
  std::vector<std::vector<int>> deployment;
  std::vector<std::vector<int>> retMatrix;
  std::vector<int> row;
  int biggest = 0;
  int cnt = 0;

  for (int i = 0; i < 4; i += 2) {
    for (int m = 0; m < 4; m += 2) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          row.push_back(v.at(i + j).at(m + k));
        }
      }
      deployment.push_back(row);
      row.clear();
    }
  }

  for (int i = 0; i < 4; ++i) {
    biggest = 0;
    for (int j = 0; j < 4; ++j) {
      biggest = std::max(biggest, deployment.at(i).at(j));
    }
    row.push_back(biggest);
    ++cnt;
    if (cnt != 2)
      continue;
    retMatrix.push_back(row);
    row.clear();
    cnt = 0;
  }

  return retMatrix;
}

void print_matrix(const std::vector<std::vector<int>> &v)
{
  for (auto row : v) {
    for (auto e : row) {
      std::cout << e << ' ';
    }
    std::cout << std::endl;
  }
}

int main()
{
  std::vector<std::vector<int>> v =
    {{1, 3, 2, 4},
      {3, 5, 2, 1},
      {8, 7, 6, 5},
      {1, 5, 9, 1}};

  v = max_pooling(v);

  print_matrix(v);

  return 0;
}
