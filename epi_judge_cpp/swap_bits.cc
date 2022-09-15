#include "test_framework/generic_test.h"
long long SwapBits(long long x, int i, int j) {
    /**
     * Since the type is long long, we need "L"
     * in order to extend past 32 bits.
     */
    if (((x >> i) & 0x1) != ((x >> j) & 0x1)) {
        x ^= (1LL << i) | (1LL << j);
    }

    return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
