# Build the html_writer library

add_library(html_writer html_writer.cpp)
target_link_libraries(html_writer PUBLIC cxx_setup)