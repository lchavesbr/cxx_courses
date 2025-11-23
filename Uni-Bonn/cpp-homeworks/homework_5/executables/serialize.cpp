#include <filesystem>
#include <format>
#include <homework_5/homework_5.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << std::format("Usage: {} <image input filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const std::string kFilename{argv[1]};

  cv::Mat image = cv::imread(kFilename, cv::IMREAD_UNCHANGED);

  if (image.empty()) {
    std::cerr << std::format("File format not supported.\n");
    return EXIT_FAILURE;
  }

  // Compute SIFTs descriptors
  auto [descriptors, image_with_keypoints] = ipb::Compute_Sift(kFilename);

  // Apply ".bin" extension in filename
  std::string const kBinary_extension(".bin");
  std::filesystem::path fs_filename{kFilename};
  fs_filename.replace_extension(kBinary_extension);

  // Serialize input image with keypoints
  ipb::serialization::Serialize(image_with_keypoints, fs_filename.filename());
  // Serialize SIFTs descriptors
  // ipb::serialization::Serialize(descriptors, fs_filename.filename());

  // Display Input image;

  std::string const kInput_image_window_name = "Input image window";

  cv::namedWindow(kInput_image_window_name, cv::WINDOW_AUTOSIZE);
  cv::imshow(kInput_image_window_name, image_with_keypoints);
  cv::waitKey(0);

  return 0;
}