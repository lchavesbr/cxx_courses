#include <homework_5/compute_sift/compute_sift.hpp>
#include <homework_5/convert_dataset/convert_dataset.hpp>
#include <homework_5/serialization/serialization.hpp>
#include <string>

namespace ipb::serialization::sifts {

void ConvertDataset(const std::filesystem::path& img_path) {
  std::string const kExtension = ".png";
  std::filesystem::path bin_path{img_path.parent_path()};
  bin_path.append("bin/");

  std::filesystem::create_directories(bin_path);

  for (auto& p : std::filesystem::directory_iterator(img_path)) {
    if (kExtension.compare(p.path().extension()) == 0) {
      auto [descriptors, image_with_keypoints] = ipb::Compute_Sift(p.path());

      std::string bin_filename = bin_path;
      bin_filename.append(p.path().stem());
      bin_filename.append(".bin");
      ipb::serialization::Serialize(descriptors, bin_filename);
    }
  }
}

std::vector<cv::Mat> LoadDataset(const std::filesystem::path& bin_path) {
  std::string const kExtension = ".bin";

  std::vector<cv::Mat> bin_img_vec;

  for (auto& p : std::filesystem::directory_iterator(bin_path)) {
    if (kExtension.compare(p.path().extension()) == 0) {
      bin_img_vec.emplace_back(
          ipb::serialization::Deserialize(p.path().string()));
    }
  }
  return bin_img_vec;
}

}  // namespace ipb::serialization::sifts