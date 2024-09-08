/******************************************************
#@Description : Implementation of image_browser utility
#@Author : Leonardo Anjos Chaves [lchavesbr @gmail.com]
#@Date : 12 / Jul / 2024
#Copyright(c) 2024 Leonardo Chaves, all rights reserved
******************************************************/
#include "image_browser.hpp"
#include "html_writer.hpp"

void image_browser::AddFullRow(const ImageRow &row, bool first_row) {

  html_writer::OpenRow();
  bool highlight = false;

  if (first_row)
    highlight = true;

  html_writer::AddImage(std::get<0>(row[0]), std::get<1>(row[0]), highlight);
  html_writer::AddImage(std::get<0>(row[1]), std::get<1>(row[1]), false);
  html_writer::AddImage(std::get<0>(row[2]), std::get<1>(row[2]), false);

  html_writer::CloseRow();
}

void image_browser::CreateImageBrowser(const std::string &title,
                                       const std::string &stylesheet,
                                       const std::vector<ImageRow> &rows) {

  html_writer::OpenDocument();
  html_writer::AddTitle(title);
  html_writer::AddCSSStyle(stylesheet);
  html_writer::OpenBody();
  bool first_row = true;
  for (unsigned int i = 0; i < rows.size(); i++) {
    if (i > 0)
      first_row = false;
    AddFullRow(rows[i], first_row);
  }
  html_writer::CloseBody();
  html_writer::CloseDocument();
}