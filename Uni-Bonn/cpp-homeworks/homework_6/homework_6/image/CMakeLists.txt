add_library(image STATIC image.cpp)
target_link_libraries(image PUBLIC io_tools cxx_setup)