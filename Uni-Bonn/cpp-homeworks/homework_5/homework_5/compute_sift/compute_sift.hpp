#pragma once

#include <opencv2/opencv.hpp>
#include <string>
namespace ipb {
std::tuple<cv::Mat, cv::Mat> Compute_Sift(const std::string& filename);
};  // namespace ipb