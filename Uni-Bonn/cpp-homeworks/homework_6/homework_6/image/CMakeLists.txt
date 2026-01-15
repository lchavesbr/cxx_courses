add_library(libimage STATIC image.cpp)
target_link_libraries(libimage PUBLIC libio_tools)