/******************************************************
#@Description : Implementation of image_browser utility
#@Author : Leonardo Anjos Chaves [lchavesbr @gmail.com]
#@Date : 17 / Oct / 2025
#Copyright(c) 2025 Leonardo Chaves, all rights reserved
******************************************************/

#include <homework_3/html_writer/html_writer.hpp>
#include <homework_3/image_browser/image_browser.hpp>

namespace image_browser {

void AddFullRow(const ImageRow& row, bool first_row) {
    html_writer::OpenRow();
    bool highlight = false;

    if (first_row) highlight = true;

    html_writer::AddImage(std::get<0>(row[0]), std::get<1>(row[0]), highlight);
    html_writer::AddImage(std::get<0>(row[1]), std::get<1>(row[1]), false);
    html_writer::AddImage(std::get<0>(row[2]), std::get<1>(row[2]), false);

    html_writer::CloseRow();
}

void CreateImageBrowser(const std::string& title,
                        const std::string& stylesheet,
                        const std::vector<ImageRow>& rows) {
    html_writer::OpenDocument();
    html_writer::AddTitle(title);
    html_writer::AddCSSStyle(stylesheet);
    html_writer::OpenBody();
    bool first_row = true;
    for (unsigned int i = 0; i < rows.size(); i++) {
        if (i > 0) first_row = false;
        AddFullRow(rows[i], first_row);
    }
    html_writer::CloseBody();
    html_writer::CloseDocument();
}
}  // namespace image_browser