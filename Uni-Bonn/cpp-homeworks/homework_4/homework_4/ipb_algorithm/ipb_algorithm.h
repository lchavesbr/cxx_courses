#ifndef IPB_ALGORITHM_H
#define IPB_ALGORITHM_H

#include <homework_4/named_vector/named_vector.h>
namespace ipb {
int accumulate(named_vector<int>& obj, int init);
int count(named_vector<int>& obj, int ref);
bool all_even(named_vector<int>& obj);
void clamp(named_vector<int>& obj, int kMin, int kMax);
void print(named_vector<int>& obj);
void fill(named_vector<int>& obj, int kValue);
bool find(named_vector<int>& obj, int kValue);
std::string& toupper(named_vector<int>& obj);
void sort(named_vector<int>& obj);
void rotate(named_vector<int>& obj, unsigned int pos);
void reverse(named_vector<int>& obj);

}  // namespace ipb
#endif  // IPB_ALGORITHM_H