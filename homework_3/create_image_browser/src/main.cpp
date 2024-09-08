/******************************************************
#@Description : Simple test program to evaluate html utility library
#@Author : Leonardo Anjos Chaves[lchavesbr @gmail.com]
#@Date : 12 / Jul / 2024
#Copyright(c) 2024 Leonardo Chaves, all rights reserved
******************************************************/

#include <cstdlib>
#include <image_browser.hpp>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

int main(int argc, char *argv[]) {

  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " [Page title] [css file source]"
              << std::endl;
    return EXIT_FAILURE;
  }

  const std::string title{argv[1]};
  const std::string stylesheet{argv[2]};
  std::vector<image_browser::ImageRow> rows;

  std::array<image_browser::ScoredImage, 3> img;
  img[0] = std::make_tuple("data/000000.png", 0.999999f);
  img[1] = std::make_tuple("data/000100.png", 0.888888f);
  img[2] = std::make_tuple("data/000200.png", 0.777777f);

  rows.push_back(img);
  img[0] = std::make_tuple("data/000300.png", 0.699999f);
  img[1] = std::make_tuple("data/000400.png", 0.588888f);
  img[2] = std::make_tuple("data/000500.png", 0.477777f);

  rows.push_back(img);

  img[0] = std::make_tuple("data/000600.png", 0.399999f);
  img[1] = std::make_tuple("data/000700.png", 0.288888f);
  img[2] = std::make_tuple("data/000800.png", 0.177777f);

  rows.push_back(img);
  image_browser::CreateImageBrowser(title, stylesheet, rows);

  return EXIT_SUCCESS;
}