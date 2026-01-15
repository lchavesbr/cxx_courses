
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <homework_6/image/image.hpp>
#include <homework_6/io_tools/io_tools.hpp>
#include <print>

namespace igg {
using std::size_t;
using std::ranges::copy_backward;

Image::Image() : rows_{}, cols_{}, max_val_{} {};
Image::Image(int rows, int cols) : rows_{rows}, cols_{cols}, max_val_{} {
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

bool Image::WriteToPgm(const std::string& file_name) const {
  io_tools::ImageData img_data{
      .rows = rows_, .cols = cols_, .max_val = max_val_, .data = data_};
  return io_tools::WriteToPgm(img_data, file_name);
}

int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }

std::uint8_t Image::at(int row, int col) const {
  return data_[(row * cols_) + col];
}
std::uint8_t& Image::at(int row, int col) {
  return data_.at((col) + (row * cols()));
}

void Image::PrintImageInfo() const {
  std::println("Rows: {} \t Cols: {} \t Max_value: {} \t Data_vector_size: {}",
               rows_, cols_, max_val_, data_.size());
}

void Image::PrintSampleData(std::size_t data_idx) const {
  auto [r, c] = From1DIndexTo2DParams(data_idx);
  std::println("idx: {} \t [{},{}] = ", data_idx, r, c,
               this->at(static_cast<int>(r), static_cast<int>(c)));
}

std::vector<float> Image::ComputeHistogram(int bins) const {
  // Histogram initialization;
  std::vector<float> histogram(bins, 0);

  // Calculate the bin width.
  float const kBin_width =
      static_cast<float>(max_val_) / static_cast<float>(bins);

  int const kTotal_pixel = rows() * cols();

  // Calculate the bin index that each sample belongs.
  for (std::uint8_t value : data_) {
    std::size_t idx = 0;
    if (value < max_val_) {
      idx = HistogramBinIndex(kBin_width, value);
    } else {
      idx = HistogramBinIndex(kBin_width, value) - 1;
    }
    histogram[idx]++;
  }

  std::ranges::for_each(histogram, [&kTotal_pixel](float& w) {
    w = w / static_cast<float>(kTotal_pixel);
  });

  return histogram;
}

std::size_t Image::HistogramBinIndex(float const& kBin_width,
                                     std::uint8_t const& value) const {
  return (static_cast<int>(std::trunc(static_cast<float>(value) / kBin_width)));
}

void Image::ShowHistogram(std::vector<float> const& histogram) const {
  size_t idx = 0;
  for (auto weight : histogram) {
    std::println("histogram[{}]:{}", idx, weight);
    idx++;
  }
  // std::ranges::for_each(histogram, [&histogram](float const
  // data){std::println("index [{}]: \t {}",data);});
}

void Image::DownScale(int scale) {
  if (scale <= 1) return;

  const size_t new_row_ = std::floor(rows() / scale);
  const size_t new_col_ = std::floor(cols() / scale);
  const size_t new_size = new_row_ * new_col_;

  std::vector<std::uint8_t> scaled_img(new_size, 0);

  size_t original_idx{}, dest_idx{};

  // loop destination 1D vector scaled_img
  for (size_t r = 0; r < new_row_; r++) {
    size_t orig_row = r * scale;
    for (size_t c = 0; c < new_col_; c++) {
      dest_idx = (r * new_col_) + c;
      original_idx = (orig_row * cols_) + (c * scale);
      scaled_img.at(dest_idx) = data_.at(original_idx);
    }
  }

  // Update downscaled Image parameters
  data_ = scaled_img;
  rows_ = rows_ / scale;
  cols_ = cols_ / scale;
}

void Image::UpScale(int scale) {
  if (scale <= 1) return;

  const size_t new_row_ = (rows() * scale);
  const size_t new_col_ = (cols() * scale);
  const size_t new_size = new_row_ * new_col_;

  std::vector<std::uint8_t> scaled_img;
  scaled_img.reserve(new_size);

  size_t original_idx{};

  // Implementation of Nearest Neighbor Method
  // loop 1D original image
  for (auto r = 0; r < rows_; r++) {
    // Create new destination row including upsampled columns as std::vector;
    std::vector<std::uint8_t> scaled_row(new_row_, 0);

    for (auto c = 0; c < cols_; c++) {
      original_idx = r * cols_ + c;

      for (auto i = 0; i < scale; i++) {
        scaled_row.at(c * scale + i) = data_.at(original_idx);
      }
    }
    // After computing upscaled columns and saving in new row, copy the entire
    // row 'scaled-times' to destination image.
    for (auto i = 0; i < scale; i++) {
      std::ranges::copy(scaled_row.begin(), scaled_row.end(),
                        std::back_inserter(scaled_img));
    }
  }
  // Update upscaled Image paramenters
  data_ = scaled_img;
  rows_ = static_cast<int>(new_row_);
  cols_ = static_cast<int>(new_col_);
}

std::pair<std::size_t, std::size_t> Image::From1DIndexTo2DParams(
    std::size_t index) const {
  std::size_t row{}, col{};

  row = index / cols_;
  col = index % cols_;
  return std::make_pair(row, col);
}

}  // namespace igg