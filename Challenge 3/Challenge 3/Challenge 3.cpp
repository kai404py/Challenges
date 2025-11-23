//
//  main.cpp
//  Challenge 3
//
//  Created by Kai on 23/11/2025.
//

#include <iostream>
#include <string>
#include <cmath>

int main(int argc, const char* argv[]) {

    double x;

    std::cout << "Please enter a number: ";

    while (!(std::cin >> x)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cerr << "[!] ERROR: I was expecting a number, not a string. Exiting.\n";
        return 1;
    }

    double neg = -x;
    double abs_x = std::abs(x);
    double pow2 = x * x;
    double pow3 = x * x * x;

    double sqrt_x = std::sqrt(std::abs(x));

    double floor_x = std::floor(x);
    double ceil_x = std::ceil(x);
    double round_x = std::round(x);

    std::cout << "neg(x): " << neg << "\n";
    std::cout << "abs(x): " << abs_x << "\n";
    std::cout << "pow2(x): " << pow2 << "\n";
    std::cout << "pow3(x): " << pow3 << "\n";
    std::cout << "sqrt(x): " << sqrt_x << "\n";
    std::cout << "floor(x): " << floor_x << "\n";
    std::cout << "ceil(x): " << ceil_x << "\n";
    std::cout << "round(x): " << round_x << "\n";

    return 0;
}
