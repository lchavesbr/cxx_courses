#include <homework_5/compute_sift/compute_sift.hpp>
#include <vector>
namespace ipb {
std::tuple<cv::Mat, cv::Mat> Compute_Sift(const std::string& filename) {
  const cv::Mat kInput = imread(filename, cv::IMREAD_GRAYSCALE);

  // detect keypoints
  auto detector = cv::SiftFeatureDetector::create();
  std::vector<cv::KeyPoint> keypoints;
  detector->detect(kInput, keypoints);

  // draw keypoints to image
  cv::Mat kImage_with_keypoints;
  cv::drawKeypoints(kInput, keypoints, kImage_with_keypoints);

  // extract the SIFT descriptors;
  cv::Mat descriptors;
  auto extractor = cv::SiftDescriptorExtractor::create();
  extractor->compute(kInput, keypoints, descriptors);

  return std::make_tuple(descriptors, kImage_with_keypoints);
}

};  // namespace ipb