#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace igg {
/*
Description: image class that can store grayscale values. The class
* Can be filled from disk from a *.pgm file.
• Can be written to a *.pgm file.
• Can compute a histogram over its pixels.
• Can be resized.
*/
class Image {
 public:
  explicit Image();                    // defined constructor
  explicit Image(int rows, int cols);  // defined override constructor
  ~Image() = default;                  // default destructor;

  Image(Image const&) = default;             // copy constructor
  Image(Image&&) = default;                  // move constructor
  Image& operator=(Image const&) = default;  // copy assignment operator
  Image& operator=(Image&&) = default;       // move assignment operator

 public:
  bool FillFromPgm(const std::string& file_name);
  bool WriteToPgm(const std::string& file_name) const;
  int rows() const;
  int cols() const;
  std::uint8_t at(int row, int col) const;  // const at() method
  std::uint8_t& at(int row, int col);       // non-const at() method

  void PrintImageInfo() const;

  void PrintSampleData(std::size_t data_idx) const;

  std::vector<float> ComputeHistogram(int bins) const;

  /**
   * @brief Finds the index of bin range that sample value belongs.
   * @param kBin_width: width of each bin
   * @param value: sample value
   * @return bin index
   */

  std::size_t HistogramBinIndex(float const& kBin_width,
                                std::uint8_t const& value) const;

  void ShowHistogram(std::vector<float> const& histogram) const;

  /**
   * @brief Downsamples a std::vector private member data by a factor of
   * scale. No anti-aliasing / anti-blocking analyses is applied.
   * @param scale: factor of downsampling
   * @return void
   */

  void DownScale(int scale);

  /**
   * @brief Upsamples a std::vector private member data by a factor of scale
   * using the nearest neighbor method
   * @param scale: factor of upsampling
   * @return void
   */
  void UpScale(int scale);

  /**
   * @brief Convert an 1D index from serialized storaged image data in a
   * std::vector to a 2D (row, col) params.
   * @param scale: index of image data_
   * @return binding value as std::pair as [ROW ,COL] order.
   */
  std::pair<std::size_t, std::size_t> From1DIndexTo2DParams(
      std::size_t index) const;

 private:
  int rows_;
  int cols_;
  std::uint8_t max_val_;
  std::vector<std::uint8_t> data_;
};
};  // namespace igg
#endif  // IMAGE_HPP
