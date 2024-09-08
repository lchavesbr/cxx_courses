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
  auto each_element = [&obj, min, max](int i) {
    obj.vector(i) = std::clamp(obj.vector(i), min, max);
  };

  std::cout << obj.vector(0) << "\n";
  std::cout << obj.vector(1) << "\n";
  std::cout << obj.vector(2) << "\n";
  std::cout << obj.vector(3) << "\n";

  // };
  //  std::transform(obj.vector().cbegin(), obj.vector().cend(),
  //                 obj.vector().begin(), each_element);
  std::for_each(obj.vector().begin(), obj.vector().end(), each_element);
  std::cout << obj.vector(0) << "\n";
  std::cout << obj.vector(1) << "\n";
  std::cout << obj.vector(2) << "\n";
  std::cout << obj.vector(3) << "\n";
}