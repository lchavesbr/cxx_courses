#ifndef MAT_SERIALIZATION_HPP
#define MAT_SERIALIZATION_HPP

#include <opencv2/opencv.hpp>
#include <string>

void Serialize(const cv::Mat& m, const std::string& filename);
cv::Mat Deserialize(const std::string& filename);

#endif  // MAT_SERIALIZATION_HPP