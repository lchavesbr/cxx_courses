#include <homework_6/image/image.hpp>
#include <homework_6/io_tools/io_tools.hpp>

namespace igg {
Image::Image() : rows_{}, cols_{} {};
Image::Image(int rows, int cols) : rows_{rows}, cols_{cols} {
  data_.resize(rows_ * cols_);
};

bool Image::FillFromPgm(const std::string& file_name) {
  io_tools::ImageData src_pgm = io_tools::ReadFromPgm(file_name);
  rows_ = src_pgm.rows;
  cols_ = src_pgm.cols;
  max_val_ = src_pgm.max_val;
  data_ = src_pgm.data;

  return !data_.empty();
}
bool Image::WriteToPgm(const std::string& file_name) {
  io_tools::ImageData img_data{rows_, cols_, max_val_, data_};
  io_tools::WriteToPgm(img_data, file_name, const std::string& file_name);
  return true;
}
}  // namespace igg