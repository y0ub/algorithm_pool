#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> matrix_mult(
    const std::vector<int> &vec,
    const std::vector<std::vector<int>> &matrix)
{
  if (vec.size() == 0 || matrix.size() == 0) {
    std::cerr << "invalid caluclation. size == 0." << std::endl;
    return {};
  }

  int vec_len = vec.size();
  int matrix_height = matrix.size();

  if (vec_len != matrix_height) {
    std::cerr << "cannot mult. left column is not equal to right row." << std::endl;
    return {};
  }

  int matrix_width = matrix.at(0).size();

  std::vector<int> ret_vec;
  ret_vec.resize(matrix_width);

  for (int k = 0; k < matrix_width; ++k) {
    int sum = 0;
    for (int j = 0; j < vec_len; ++j) {
      sum += vec.at(j) * matrix.at(j).at(k);
    }
    ret_vec.at(k) = sum;
  }

  return ret_vec;
}

int relu(const int &elem)
{
  return std::max(0, elem);
}

std::vector<int> neural_network()
{
  std::vector<int> v =
    {-5, 2, 1, 2};
  std::vector<std::vector<int>> matrix =
    {{1, 2},
     {3, -3},
     {1, 1},
     {2, 1}}; // {{1}, {2}};

  auto ret = matrix_mult(v, matrix);

  const int ksize = ret.size();

  for (int i = 0; i < ksize; ++i) {
    ret.at(i) = relu(ret.at(i));
  }

  return ret;
}

void print_matrix(const std::vector<std::vector<int>> &v)
{
  for (auto row : v) {
    for (auto e : row) {
      std::cout << e << ' ';
    }
    std::cout << '\n';
  }
}

int main()
{
  auto ret = neural_network();
  // print_matrix(ret);
  for (auto e : ret) {
    std::cout << e << ' ';
  }

  return 0;
}
