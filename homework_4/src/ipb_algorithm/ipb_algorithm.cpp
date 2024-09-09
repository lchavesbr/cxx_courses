#include "homework_4/named_vector.h"
#include <algorithm>
#include <homework_4/ipb_algorithm.h>
#include <numeric>

int ipb::accumulate(ipb::named_vector<int> const &obj) {
  return std::accumulate((obj.vector()).begin(), (obj.vector()).end(), 0);
}

int ipb::count(ipb::named_vector<int> const &obj, int ref) {
  return std::count((obj.vector()).begin(), (obj.vector()).end(), ref);
}

bool ipb::all_even(ipb::named_vector<int> const &obj) {
  auto isEven = [](int i) { return (i % 2) == 0; };
  return std::all_of((obj.vector()).begin(), (obj.vector()).end(), isEven);
}
void ipb::clamp(ipb::named_vector<int> &obj, int const min, int const max) {
  int i = 0;
  for (auto n : obj.vector()) {
    obj.vector(i) = std::clamp(n, min, max);
    i++;
  }
}