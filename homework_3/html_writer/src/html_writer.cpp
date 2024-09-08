/******************************************************
#@Description : Implementation of html_writer utility
#@Author : Leonardo Anjos Chaves [lchavesbr @gmail.com]
#@Date : 12 / Jul / 2024
#Copyright(c) 2024 Leonardo Chaves, all rights reserved
******************************************************/
#include "html_writer.hpp"
#include <filesystem>
#include <iostream>

void html_writer::OpenDocument() {
  std::cout << "<!DOCTYPE html>" << std::endl;
  std::cout << "<html>" << std::endl;
}

void html_writer::CloseDocument() { std::cout << "</html>" << std::endl; }

void html_writer::AddCSSStyle(const std::string &stylesheet) {
  std::cout << "<head>" << std::endl;
  std::cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\""
            << stylesheet << "\" />" << std::endl;
  std::cout << "</head>" << std::endl;
}

void html_writer::AddTitle(const std::string &title) {
  std::cout << "<title>" << title << "</title>" << std::endl;
}

void html_writer::OpenBody() { std::cout << "<body>" << std::endl; }

void html_writer::CloseBody() { std::cout << "</body>" << std::endl; }

void html_writer::OpenRow() { std::cout << "<div class=\"row\">" << std::endl; }

void html_writer::CloseRow() { std::cout << "</div>" << std::endl; }

void html_writer::AddImage(const std::string &img_path, float score,
                           bool highlight) {

  const std::filesystem::path html_img_path{img_path};
  const std::string img_title{html_img_path.stem()};
  const std::string img_extension{html_img_path.extension()};

  if (img_extension != ".jpg" && img_extension != ".png") {
    std::cerr << "File extension not supported: " << img_extension << std::endl;
    std::cerr << "Supported file formats are: .jpg and .png" << std::endl;
    return;
  }

  std::cout << "<div class=\"column\"";
  if (highlight)
    std::cout << " style=\"border: 5px solid green;\"";

  std::cout << ">" << std::endl;
  std::cout << "<h2>" << img_title + img_extension << "</h2>" << std::endl;
  std::cout << "<img src =\"" << img_path << "\" />" << std::endl;
  std::cout << "<p>score = " << std::setprecision(2) << std::fixed << score
            << "</p>" << std::endl;
  std::cout << "</div>" << std::endl;
}