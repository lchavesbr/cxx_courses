#include <cstdlib>
#include <iostream>
#include <random>

int main() {
    // Defines min max range of guessing number;
    int const kMin = 0;
    int const kMax = 99;

    // Set the guessing number;
    std::random_device seed_rd;
    std::uniform_int_distribution<int> dist(kMin, kMax);
    int guessed_number = dist(seed_rd);

    do {
        std::cout << "Enter your guessing number [0-99]: ";
        int number;
        std::cin >> number;

        // Error output if user enter a non-integer type.
        if (std::cin.fail()) {
            std::cerr << "Error encontered, exiting...\n";
            return EXIT_FAILURE;
        }

        if (number < kMin || number > kMax) {
            std::cerr << "[WARNING] : Number must be between 0 and 99"
                      << std::endl;
        }

        if (number > guessed_number && number <= kMax)
            std::cout << "The number is smaller. Try again\n";

        if (number < guessed_number && kMin <= number)
            std::cout << "The number is greater. Try again\n";

        if (number == guessed_number) {
            break;
        }
    } while (true);

    std::cout << "Congratulations!!!\n";
    std::cout << "You guessed the number:   " << guessed_number << std::endl;

    return EXIT_SUCCESS;
}