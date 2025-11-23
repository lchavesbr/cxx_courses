#include <filesystem>
#include <format>
#include <homework_5/homework_5.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << std::format("Usage: {} <binary image input filename>\n",
                             argv[0]);
    return EXIT_FAILURE;
  }

  const std::string kFilename{argv[1]};

  // Check the ".bin" extension in filename
  std::string const kBinary_extension(".bin");
  std::filesystem::path fs_filename{kFilename};

  if (kFilename.compare(fs_filename.filename()) != 0) {
    std::cerr << std::format(
        "Binary file format not supported. It must be '.bin'\n");
    return EXIT_FAILURE;
  }

  // Deserialize input image with keypoints
  cv::Mat image_with_keypoints = ipb::serialization::Deserialize(kFilename);

  // Display Input image;
  std::string const kInput_image_window_name = "Input image window";

  cv::namedWindow(kInput_image_window_name, cv::WINDOW_AUTOSIZE);
  cv::imshow(kInput_image_window_name, image_with_keypoints);
  cv::waitKey(0);

  return 0;
}