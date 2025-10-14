#include <cstdlib>
#include <iostream>
#include <random>
#include <sstream>

int main(int argc, char** argv) {
    // Checks usage and parameters;
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " filname1 filename2" << std::endl;
        return EXIT_FAILURE;
    }

    std::string const extension_txt{".txt"};
    std::string const extension_png{".png"};

    // Load params from filename1;
    std::stringstream sstring1{std::string(argv[1])};
    int num1 = 0;
    std::string ext1{};
    sstring1 >> num1 >> ext1;

    // Load params from filename 2;
    std::stringstream sstring2{std::string(argv[2])};
    int num2 = 0;
    std::string ext2{};
    sstring2 >> num2 >> ext2;

    std::cout << "Num   :" << num1 << "     Ext  :" << ext1 << std::endl;
    std::cout << "Num   :" << num2 << "     Ext  :" << ext2 << std::endl;

    float ret_value = 0;
    if (ext1 == extension_txt && ext2 == extension_txt) {
        ret_value = (num1 + num2) / 2;
    } else if (ext2 == extension_png && ext1 == extension_png) {
        ret_value = num1 + num2;
    } else if (ext1 == extension_txt && ext2 == extension_png) {
        ret_value = num1 % num2;
    }

    std::cout << ret_value;

    return EXIT_SUCCESS;
}