#include <cmath>
#include <iostream>
#include <vector>

int next_prime(const std::vector<bool>& flags, int prime) {
  int next = prime + 1;
  while (next < flags.size() && !flags.at(next))
    ++next;

  return next;
}

void cut_off_multiple(std::vector<bool>& flags, const int& prime) {
  for (int i = prime * prime; i < flags.size(); i += prime)
    flags.at(i) = false;
}

std::vector<bool> sieve_of_eratosthenes(const int& max) {
  std::vector<bool> flags(max + 1, true);

  flags.at(0) = flags.at(1) = false;
  int prime = 2;

  while (prime <= sqrt(max)) {
    cut_off_multiple(flags, prime);

    prime = next_prime(flags, prime);
  }

  return flags;
}

int main() {
  auto ret = sieve_of_eratosthenes(100);

  int i = 0;
  for (auto e : ret) {
    if (e)
      std::cout << i << " is prime." << '\n';
    ++i;
  }
  return 0;
}
