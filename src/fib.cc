#include <iostream>

unsigned int memo[256];

unsigned int fib(int n)
{
  if (n == 0 || n == 1)
    return n;
  else {
    if (memo[n] == 0)
      memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
  }
}

int main()
{
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i)
    std::cout << fib(i) << ' ';
  return 0;
}
