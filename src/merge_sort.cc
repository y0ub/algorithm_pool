#include <iostream>
#include <vector>

void merge(std::vector<int> &v, const int &left, const int &right, const int &middle)
{
  int left_vec_size  = middle - left;
  int right_vec_size = right - middle + 1;
  std::vector<int> left_vec;
  std::vector<int> right_vec;

  for (int i = 0; i < left_vec_size; ++i)
    left_vec.push_back(v.at(i + left));

  for (int i = 0; i < right_vec_size; ++i)
    right_vec.push_back(v.at(i + middle));

  int i, j, k;
  i = j = 0;
  k = left;

  while (i < left_vec_size && j < right_vec_size)
    v.at(k++) = (left_vec.at(i) < right_vec.at(j))
      ? left_vec.at(i++) : right_vec.at(j++);

  while (i < left_vec_size)
    v.at(k++) = left_vec.at(i++);

  while (j < right_vec_size)
    v.at(k++) = right_vec.at(j++);
}

void merge_sort(std::vector<int> &v, const int &left, const int &right)
{
  const int middle = left + (right - left) / 2;

  if (left < right) {
    merge_sort(v, left, middle);
    merge_sort(v, middle + 1, right);
    merge(v, left, right, middle);
  }
}

int main()
{
  std::vector<int> v = {8, 4, 9, 50, 7, 18, 36};
  merge_sort(v, 0, v.size() - 1);

  std::for_each(v.begin(), v.end(), [](auto e) {std::cout << e << ' ';});
  return 0;
}
