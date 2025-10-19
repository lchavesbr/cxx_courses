#include <homework_4/ipb_algorithm/ipb_algorithm.h>

#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <numeric>

#include "homework_4/named_vector/named_vector.h"

namespace ipb {

int accumulate(named_vector<int>& obj, int init) {
    return std::accumulate(obj.vector().cbegin(), obj.vector().cend(), init);
}
int count(named_vector<int>& obj, int ref) {
    return std::count((obj.vector()).cbegin(), (obj.vector()).cend(), ref);
}
bool all_even(named_vector<int>& obj) {
    return (std::all_of(obj.vector().cbegin(), obj.vector().cend(),
                        [](int i) { return (i % 2) == 0; }));
}
void clamp(named_vector<int>& obj, int const kMin, int const kMax) {
    std::for_each(obj.vector().begin(), obj.vector().end(),
                  [kMin, kMax](int& i) { i = std::clamp(i, kMin, kMax); });
}
void print(named_vector<int>& obj) {
    std::cout << std::format("{} : ", obj.name());
    std::for_each(obj.vector().cbegin(), obj.vector().cend(),
                  [](int i) { std::cout << std::format("{},", i); });
}
void fill(named_vector<int>& obj, int const kValue) {
    std::fill(obj.vector().begin(), obj.vector().end(), kValue);
}

bool find(named_vector<int>& obj, int const kValue) {
    return (std::find(obj.vector().cbegin(), obj.vector().cend(), kValue) !=
            obj.vector().cend());
}
std::string& toupper(named_vector<int>& obj) {
    // std::for_each(name_upper.begin(), name_upper.end(),
    //               [](char& c) { c = std::toupper(c); });
    std::for_each(obj.name().begin(), obj.name().end(),
                  [](char& c) { c = std::toupper(c); });

    return obj.name();
}
}  // namespace ipb