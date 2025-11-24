#include <filesystem>
#include <homework_5/homework_5.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << std::format("Usage: {} <source directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const std::string kDirectory{argv[1]};

  ipb::serialization::sifts::ConvertDataset(std::filesystem::path(kDirectory));
  return 0;
}