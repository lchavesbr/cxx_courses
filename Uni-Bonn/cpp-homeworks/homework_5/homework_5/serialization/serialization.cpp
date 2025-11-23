#include <fstream>
#include <homework_5/compute_sift/compute_sift.hpp>
#include <homework_5/serialization/serialization.hpp>
#include <iostream>

namespace ipb::serialization {
void Serialize(const cv::Mat& m, const std::string& filename) {
  std::ofstream f_out(filename, std::ios_base::out | std::ios_base::trunc |
                                    std::ios_base::binary);
  if (!f_out) {
    std::cerr << "Could not open " << filename
              << " in binary mode for writing.\n";
    return;
  };

  // Save binary Header
  int rows = m.rows;
  int cols = m.cols;
  int type = m.type();
  int channels = m.channels();
  int each_element_size = m.elemSize1();

  f_out.write(reinterpret_cast<char*>(&rows), sizeof(rows));
  f_out.write(reinterpret_cast<char*>(&cols), sizeof(cols));
  f_out.write(reinterpret_cast<char*>(&type), sizeof(type));

  auto data_ptr = m.data;
  for (int i = 0; i < rows * cols * channels * each_element_size;
       i += each_element_size) {
    f_out.write(reinterpret_cast<char*>(&data_ptr[i]), each_element_size);
  }
  f_out.close();
}

cv::Mat Deserialize(const std::string& filename) {
  std::ifstream f_in(filename, std::ios_base::in | std::ios_base::binary);

  if (!f_in) {
    std::cerr << "Could not open " << filename
              << " in binary mode for reading.\n";
    return cv::Mat::zeros(0, 0, CV_8UC3);
  }

  int rows{};
  int cols{};
  int type{};

  f_in.read(reinterpret_cast<char*>(&rows), sizeof(rows));
  f_in.read(reinterpret_cast<char*>(&cols), sizeof(cols));
  f_in.read(reinterpret_cast<char*>(&type), sizeof(type));

  cv::Mat ret_bin_img = cv::Mat::zeros(rows, cols, type);

  int channels = ret_bin_img.channels();
  int each_element_size = ret_bin_img.elemSize1();

  for (int i = 0; i < rows * cols * channels * each_element_size;
       i = i + each_element_size) {
    f_in.read(reinterpret_cast<char*>(&ret_bin_img.data[i]), each_element_size);
  }

  f_in.close();
  return ret_bin_img;
}

}  // namespace ipb::serialization