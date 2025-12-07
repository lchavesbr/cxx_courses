#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace igg {

class Image {
 public:
  Image();
  Image(int rows, int cols);
  ~Image();

 public:
  bool FillFromPgm(const std::string& file_name);
  bool WriteToPgm(const std::string& file_name);

 private:
  int rows_;
  int cols_;
  uint8_t max_val_;
  std::vector<uint8_t> data_;
};
};  // namespace igg
#endif  // IMAGE_HPP