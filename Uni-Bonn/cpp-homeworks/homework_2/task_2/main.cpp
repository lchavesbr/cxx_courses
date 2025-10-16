#include <cstdlib>
#include <iostream>
#include <random>
#include <sstream>

int main(int argc, char** argv) {
    // Checks usage and parameters;
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " [filename 1] [filename 2] \n";
        std::cerr << "Please, note that filename has the following format: "
                     "<INT>.<EXT> \n";
        std::cerr << "Supported extensions are: .txt and .png only.\n";
        return EXIT_FAILURE;
        return EXIT_FAILURE;
    }

    std::string const extension_txt{".txt"};
    std::string const extension_png{".png"};

    // Load params from filename1;
    std::stringstream sstring1{std::string(argv[1])};
    int num1{};
    std::string ext1{};
    sstring1 >> num1 >> ext1;

    // Load params from filename 2;
    std::stringstream sstring2{std::string(argv[2])};
    int num2{};
    std::string ext2{};
    sstring2 >> num2 >> ext2;

    std::cout << "Num   :" << num1 << "     Ext  :" << ext1 << "\n";
    std::cout << "Num   :" << num2 << "     Ext  :" << ext2 << "\n";

    float ret_value = 0;
    if (ext2 == extension_txt && ext1 == extension_txt) {
        ret_value = (num1 + num2) / 2;
    } else if (ext2 == extension_png && ext1 == extension_png) {
        ret_value = num1 + num2;
    } else if (ext1 == extension_txt && ext2 == extension_png) {
        ret_value = num1 % num2;
    } else {
        std::cerr << "Error found in filenames. Please, mind the format must "
                     "be: <INT>.<EXT> \n";
        std::cerr << "Supported extensions are: .txt and .png only.\n";
        return EXIT_FAILURE;
    }

    std::cout << ret_value;

    return EXIT_SUCCESS;
}