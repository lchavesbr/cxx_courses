#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

int main(int argc, char** argv) {
  cv::Mat image = cv::imread(argv[1], cv::IMREAD_COLOR);

  cv::namedWindow("Original Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Original Image", image);

  auto detector = cv::SiftFeatureDetector::create();
  std::vector<cv::KeyPoint> keypoints;
  detector->detect(image, keypoints);

  cv::Mat image_with_keypoints;
  cv::drawKeypoints(image, keypoints, image_with_keypoints);

  cv::namedWindow("Keypoints Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Keypoints Image", image_with_keypoints);

  cv::waitKey(0);
  return 0;
}