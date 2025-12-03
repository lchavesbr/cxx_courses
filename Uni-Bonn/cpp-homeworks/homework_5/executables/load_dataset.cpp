#include <algorithm>
#include <filesystem>
#include <format>
#include <homework_5/homework_5.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << std::format("Usage: {} <source BIN directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const std::string kDirectory{argv[1]};

  std::vector<cv::Mat> bin_vec =
      ipb::serialization::sifts::LoadDataset(std::filesystem::path(kDirectory));
  std::cout << std::format("Total bin files loaded: {}\n", bin_vec.size());
  std::for_each(bin_vec.begin(), bin_vec.end(), [](cv::Mat img) {
    std::cout << std::format("img: rows {} cols {} type {}\n", img.rows,
                             img.cols, img.type());
  });
  return 0;
}