#ifndef NAMED_VECTOR_H
#define NAMED_VECTOR_H
//#include <cstddef>
#include <string>
#include <vector>

namespace ipb {

template <typename T> class named_vector {
public:
  std::vector<T> const &vector() const { return data_; } /*Getter*/
  T &vector(int i) { return data_[i]; }
  std::string const &name() const { return name_; } /*Getter*/
  void set_vector(std::vector<T> const &data) { data_ = data; }; /*Setter Vector*/
  void set_name(std::string const &name) { name_ = name; }; /*Setter Name*/

  int size() const { return (name_.size() + data_.size()); }
  bool isEmpty() const { return (name_.empty() || data_.empty()); }
  void reserve(std::size_t new_reserved_size) {
    data_.reserve(new_reserved_size);
  }
  void resize(std::size_t count) { data_.resize(count); }
  std::size_t capacity() const { return data_.capacity(); }

public:
  explicit named_vector<T>(std::string &name, std::vector<T> &data)
      : name_{name}, data_{data} {}
  virtual ~named_vector<T>() = default;
  named_vector<T>(named_vector<T> &) = default;  // copy constructor
  named_vector<T>(named_vector<T> &&) = default; // move constructor
  named_vector<T> &
  operator=(named_vector<T> &) = default; // assignment operator
  named_vector<T> &
  operator=(named_vector<T> &&) = default; // move assignment operator

private:
  std::string name_;
  std::vector<T> data_;
};
} // namespace ipb
#endif