#include "test_framework/generic_test.h"

short Parity(unsigned long long x) {
  int num_bits = sizeof(x) * 8;
  char look_up[16] = {0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0};

  short parity = 0;
  for (int i = 0; i < num_bits; i += 4) {
    int val = x & 0xF;
    parity ^= look_up[val];

    x >>= 4;
  }

  return parity;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
