#ifndef IPB_ALGORITHM_H
#define IPB_ALGORITHM_H

#include "named_vector.h"
namespace ipb {

int accumulate(named_vector<int> const &obj);
int count(named_vector<int> const &obj, int ref);
bool all_even(named_vector<int> const &obj);
void clamp(named_vector<int> &obj, int const min, int const max);
}; // namespace ipb
#endif