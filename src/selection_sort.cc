#include <iostream>
#include <vector>

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

void selection_sort(std::vector<int> &v)
{
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    int min_elem_index = i;
    for (int j = i + 1; j < n; ++j) {
      min_elem_index = v.at(min_elem_index) < v.at(j) ? min_elem_index : j;
    }
    swap(v.at(i), v.at(min_elem_index));
  }
}

void print_elements(std::vector<int> &v)
{
  std::for_each(v.begin(), v.end(), [](auto e){std::cout << e << ' ';});
  std::cout << '\n';
}

int main()
{
  std::vector<int> v = {8, 49, 1, 9, 35, 8, 90, 17, 5, 100};
  print_elements(v);
  selection_sort(v);
  print_elements(v);
}
