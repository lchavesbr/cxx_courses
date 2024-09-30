#ifndef IPB_ALGORITHM_H
#define IPB_ALGORITHM_H

#include "named_vector.h"
namespace ipb {

int accumulate(named_vector<int> const &obj);
int count(named_vector<int> const &obj, int ref);
bool all_even(named_vector<int> const &obj);
void clamp(named_vector<int> &obj, int const min, int const max);
void fill(named_vector<int> &obj, int const &kValue);
bool find(named_vector<int> const &obj, int const &k);
std::string print(named_vector<int> const &obj);
std::string toupper(named_vector<int> const &obj);
std::vector<int> sort(named_vector<int> const &obj);
std::vector<int> rotate(named_vector<int> const &obj);
std::vector<int> reverse(named_vector<int> const &obj);
}; // namespace ipb
#endif