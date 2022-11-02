#include <iostream>

int sqrt_helper(int n, int min, int max)
{
  if (max < min)
    return -1;

  int middle = min + (max - min) / 2;

  if (middle * middle == n)
    return middle;
  else if (middle * middle < n)
    return sqrt_helper(n, middle + 1, max);
  else
    return sqrt_helper(n, min, middle - 1);

}

int y0_sqrt(int n)
{
  return sqrt_helper(n, 1, n);
}

int main()
{
  for (int i = 1; i <= 100; ++i) {
    std::cout << i << ": " << y0_sqrt(i) << std::endl;
  }
}
