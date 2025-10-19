/******************************************************
#@Description : Example application to test ipb_algorithm lib
#@Author : Leonardo Anjos Chaves    [lchavesbr @gmail.com]
#@Date : 19 / Oct / 2025
#Copyright(c) 2025 Leonardo Chaves, all rights reserved
******************************************************/

#include <homework_4/homework_4.h>

#include <format>
#include <iostream>

#include "homework_4/ipb_algorithm/ipb_algorithm.h"

int main() {
    std::cout << "Hello world from Homework_4.\n";

    std::string myname{"Leonardo"};
    std::vector<int> myvec{2, 4, 6, 8, 10};
    ipb::named_vector<int> mynamed_vec(myname, myvec);

    std::cout << "[accumulate]: \t" << ipb::accumulate(mynamed_vec, 0) << "\n";
    std::cout << "[count]: \t" << ipb::count(mynamed_vec, 1) << "\n";
    std::cout << "[all_even]: \t"
              << std::format("{}\n", ipb::all_even(mynamed_vec));

    std::cout << "[print]: \t";
    ipb::print(mynamed_vec);
    std::cout << "\n";

    std::cout << "[clamp]: \t";
    ipb::clamp(mynamed_vec, 1, 5);
    ipb::print(mynamed_vec);
    std::cout << "\n";

    std::cout << "[fill]: \t";
    ipb::fill(mynamed_vec, -10);
    ipb::print(mynamed_vec);
    std::cout << "\n";

    std::cout << "[find]: \t" << std::format("{}\n", ipb::find(mynamed_vec, 0));

    std::cout << "[toupper]: \t"
              << std::format("{}\n", ipb::toupper(mynamed_vec));

    return 0;
}