/*
#@ Description : guessing game
#@ Author: Leonardo Anjos Chaves    [lchavesbr @gmail.com]
#@ Date : 15/Oct/2025
#@ Modified :
#Copyright(c) 2025 Leonardo Chaves, all rights reserved
*/

#include <cstdlib>
#include <iostream>
#include <random>

int main() {
    // Defines min max range of guessing number;
    int const kMin = 0;
    int const kMax = 99;

    // Set the guessing number;
    std::random_device seed_rd;
    std::uniform_int_distribution<int> dist{kMin, kMax};
    int const guessed_number = dist(seed_rd);

    while (true) {
        std::cout << "Enter your guessing number [0-99]: ";
        int number{};
        std::cin >> number;

        // Error output if user enter a non-integer type.
        if (std::cin.fail()) {
            std::cerr << "Error encontered, exiting...\n";
            return EXIT_FAILURE;
        }

        if (number < kMin || number > kMax) {
            std::cerr << "[WARNING] : Number must be between 0 and 99.\n";
        }

        if (number > guessed_number && number <= kMax) {
            std::cout << "The number is smaller. Try again\n";
        }
        if (number < guessed_number && kMin <= number) {
            std::cout << "The number is greater. Try again\n";
        }
        if (number == guessed_number) {
            break;
        }
    }

    std::cout << "Congratulations!!!\n";
    std::cout << "You guessed the number:   " << guessed_number << "\n";

    return EXIT_SUCCESS;
}