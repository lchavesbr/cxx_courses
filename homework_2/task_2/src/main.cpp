/*******************************************************
#@Description : Homework 2 Task 2
#@Author : Leonardo Anjos Chaves[lchavesbr @gmail.com]
#@Date : 10 / Jul / 2024
#Copyright(c) 2024 Leonardo Chaves, all rights reserved
*********************************************************/
#include <cstdlib>
#include <iostream>
#include <sstream>

int main(int argc, const char *argv[]) {

  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [filename 1] [filename 2] \n";
    std::cerr << "Please, note that filename has the following format: "
                 "<INT>.<EXT> \n";
    std::cerr << "Supported extensions are: .txt and .png only.\n";
    return EXIT_FAILURE;
  }

  std::stringstream input_arg_1{argv[1]}, input_arg_2{argv[2]};
  int num_arg_1 = 0, num_arg_2 = 0;
  std::string ext_arg_1{}, ext_arg_2{};

  // Split the string stream using simple syntax
  input_arg_1 >> num_arg_1 >> ext_arg_1;

  if (input_arg_1.fail() ||
      ((ext_arg_1.compare(".txt")) && (ext_arg_1.compare(".png")))) {
    std::cerr << "Error found in filename 1. Please, mind the format must be: "
                 "<INT>.<EXT> \n";
    std::cerr << "Supported extensions are: .txt and .png only.\n";
    return EXIT_FAILURE;
  }

  input_arg_2 >> num_arg_2 >> ext_arg_2;
  if (input_arg_2.fail() ||
      ((ext_arg_2.compare(".txt")) && (ext_arg_2.compare(".png")))) {
    std::cerr << "Error found in filename 2. Please, mind the format must be: "
                 "<INT>.<EXT> \n";
    std::cerr << "Supported extensions are: .txt and .png only.\n";
    return EXIT_FAILURE;
  }

  std::cout << "Input argument 1: " << argv[1] << std::endl;
  std::cout << "Parsing in <int>.<ext> \t";
  std::cout << "Int: " << num_arg_1 << "\t";
  std::cout << "Ext: " << ext_arg_1 << std::endl;

  std::cout << "Input argument 2: " << argv[2] << std::endl;
  std::cout << "Parsing in <int>.<ext> \t";
  std::cout << "Int: " << num_arg_2 << "\t";
  std::cout << "Ext: " << ext_arg_2 << std::endl;

  if (ext_arg_1 == ".txt") {
    if (ext_arg_2 == ".txt") {
      std::cout << "The mean is:\n" << (num_arg_1 + num_arg_2) / 2 << std::endl;
    } else {
      std::cout << "The modulo division is:\n"
                << num_arg_1 % num_arg_2 << std::endl;
    }
  } else {
    if (ext_arg_2 == ".png") {
      std::cout << "The sum is:\n" << num_arg_1 + num_arg_2 << std::endl;
    } else {
      std::cerr << "Error found. Combination of extension not allowed."
                << std::endl;
      std::cerr << "Exiting..." << std::endl;
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}
