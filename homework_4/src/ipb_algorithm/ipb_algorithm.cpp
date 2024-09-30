#include "homework_4/named_vector.h"
#include <algorithm>
#include <homework_4/ipb_algorithm.h>
#include <charconv>
#include <numeric>
#include <iostream>
#include <cctype>

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

void ipb::fill(ipb::named_vector<int> &obj, int const &kValue){
  std::vector<int> local = obj.vector();
  std::fill(local.begin(),local.end(),kValue);
  obj.set_vector(local);
}

bool ipb::find(ipb::named_vector<int> const &obj, int const &k){
  auto ret = std::find((obj.vector()).begin(),(obj.vector()).end(),k);
  if (ret ==(obj.vector()).end() )
    return false;
  else
    return true;
}

std::string ipb::print(ipb::named_vector<int> const &obj){
  
  std::string output{};
  /*
  output = "\"" + obj.name();
  std::for_each(obj.vector().begin(), obj.vector().end(),[&output](int n){output +=  ", ";
                                                                                              output += (char)n;});                                   
  output += "\"";  
  std::cout << output << std::endl;
*/
  std::cout << "\"" + obj.name();
  std::for_each(obj.vector().begin(), obj.vector().end(),[](int n){std::cout << ", " << n;});                                   
  std::cout << "\"";
  return output;
}

std::string ipb::toupper(ipb::named_vector<int> const &obj){
  std::string upper_name{};
  std::for_each(obj.name().begin(), obj.name().end(),[&upper_name](char a){upper_name += std::toupper(a);});
  return upper_name;
}
std::vector<int> ipb::sort(ipb::named_vector<int> const &obj){
  std::vector<int> sorted_vector = obj.vector();
  std::sort(sorted_vector.begin(),sorted_vector.end());
  return sorted_vector;
}
std::vector<int> ipb::rotate(ipb::named_vector<int> const &obj){
  std::vector<int> rotated_vector = obj.vector();
  std::rotate(rotated_vector.begin(),rotated_vector.begin()+2,rotated_vector.end());
  return rotated_vector;
}
//std::vector<int> ipb::reverse(ipb::named_vector<int> const &obj){}