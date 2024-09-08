#include <cstdlib>
#include <iostream>
#include <random>
int main() {

  std::random_device seed;
  std::uniform_int_distribution<int> dist(0, 99);
  const int target_number = dist(seed); // random
  int ret = EXIT_SUCCESS;

  std::cout << "Welcome to Guessing Game!!! \n\n";
  while (true) {
    std::cout << "==============================\n";
    std::cout << "Enter your guess number (0-99): ";

    int guessed_number;

    std::cin >> guessed_number;
    if (std::cin.fail()) {
      std::cerr << "Error encountered, exiting...\n";
      ret = EXIT_FAILURE;
      break;
    } else if (guessed_number < 0 || guessed_number > 99) {
      std::cerr << "[WARNING] : Number must be between 0 and 99\n";
    } else if (guessed_number == target_number) {
      std::cout << "Congratulations!! \n";
      std::cout << "You win. ";
      break;
    } else {
      std::cout << "Almost there. ";
      if (guessed_number > target_number)
        std::cout << "Try once again with a lower number. \n";
      else
        std::cout << "Try once again with a higher number. \n";
    }
  }
  std::cout << "The target numer is " << target_number << "\n";
  return ret;
}