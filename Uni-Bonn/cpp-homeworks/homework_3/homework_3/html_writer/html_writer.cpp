// @file      html_writer.cpp
// @author    Leonardo Chaves     [lchavesbr@gmail.com]
//
// Copyright (c) 2025 Leonardo Chaves, all rights reserved

#include <filesystem>
#include <format>
#include <homework_3/html_writer/html_writer.hpp>
#include <iostream>

namespace html_writer {

void OpenDocument() {
    std::string const kOpenDoc =
            "<!DOCTYPE html>\n"
            "<html>\n";
    std::cout << kOpenDoc;
}

void CloseDocument() {
    std::string const kCloseDoc = "</html>";
    std::cout << kCloseDoc;
}

void AddCSSStyle(const std::string& stylesheet) {
    std::cout << "<head>\n";
    std::string const kCSSStyle =
            R"(<link rel="stylesheet" type="text/css" href=")" + stylesheet +
            R"(" />)" + "\n";
    std::cout << kCSSStyle;
    std::cout << "</head>\n";
}

void AddTitle(const std::string& title) {
    std::cout << R"(<title>)" << title << R"(</title>)" << "\n";
}

void OpenBody() { std::cout << "<body>\n"; }

void CloseBody() { std::cout << "</body>\n"; }

void OpenRow() { std::cout << R"(<div class="row">)" << "\n"; }

void CloseRow() { std::cout << "</div>\n"; }

void AddImage(const std::string& img_path, float score, bool highlight) {
    std::string const kExtension_png{".png"};
    std::string const kExtension_jpg{".jpg"};
    std::filesystem::path const html_img_path{img_path};
    std::string const img_title{html_img_path.stem()};
    std::string const img_extension{html_img_path.extension()};

    if (img_extension != kExtension_jpg && img_extension != kExtension_png) {
        std::cerr << "File extension not supported:\t" << img_extension << "\n";
        std::cerr << "Supported file formats are: \t" << kExtension_jpg
                  << " and " << kExtension_png << "\n";
        return;
    }

    std::string column = R"(<div class="column")";

    if (highlight) {
        column += R"( style="border: 5px solid green;")";
    }
    column += ">\n";
    std::cout << column;
    std::cout << "<h2>" << img_title + img_extension << "</h2>\n";
    std::cout << R"(<img src =")" << img_path << R"(" />)" << "\n";
    // std::cout << "<p>score = " << std::setprecision(2) << std::fixed << score
    // << "</p>\n";
    std::string const kScore = std::format("<p>score = {:.2f}</p>\n", score);
    std::cout << kScore;
    std::cout << "</div>\n";
}
}  // namespace html_writer