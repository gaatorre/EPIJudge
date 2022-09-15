#include "test_framework/generic_test.h"

short CountBits(unsigned int x) {
  int bits = (sizeof(x) * 8);
  char look_up[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

  int num_bits = 0;
  for (int i = 0; i < bits; i += 4) {
    int val = x & 0xF;
    num_bits += look_up[val];

    x >>= 4;
  }

  return num_bits;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "count_bits.cc", "count_bits.tsv", &CountBits,
                         DefaultComparator{}, param_names);
}
