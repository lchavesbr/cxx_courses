#include <filesystem>
#include <homework_6/homework_6.hpp>
#include <iostream>
#include <print>
int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::println("Show input PGM image info and copy to file.");
    std::println("Usage: {} <input_pgm_file> <output_pgm_file>", argv[0]);
  }
  std::filesystem::path input_filename{argv[1]};
  if (std::string{".pgm"} != input_filename.extension()) {
    std::println(
        "Extension not suported: {}. Please, consider a PGM image file.",
        std::string(input_filename.extension()));
    return EXIT_FAILURE;
  }
  igg::Image input;
  input.FillFromPgm(argv[1]);
  std::println("Enter the number of bins: ");
  int bins{};
  std::cin >> bins;
  input.ComputeHistogram(bins);

  std::println("Enter the scale for up/down sampling: ");
  int scale{};
  std::cin >> scale;

  input.UpScale(scale);
  // input.DownScale(scale);
  input.WriteToPgm(argv[2]);
  return EXIT_SUCCESS;
}