#include "main.h"

int input() {
    int guess;
    std::cout << "\nI'm thinking of a number between 0 and 100\n";
    std::cout << "What could it be: ";
    std::cin >> guess;
    return guess;
}

int main() {
    std::srand(std::time(nullptr));
    int randNum = std::rand() % 101; // 0–100
    int randNumGuess = -1;

    while (randNumGuess != randNum) {
        randNumGuess = input();

        int diff = std::abs(randNum - randNumGuess);

        if (diff == 0) {
            std::cout << "Guess is correct!\n";
        }
        else if (diff <= 2) {
            std::cout << "Boiling\n";
        }
        else if (diff <= 5) {
            std::cout << "Hotter\n";
        }
        else if (diff <= 10) {
            std::cout << "Hot\n";
        }
        else if (diff <= 15) {
            std::cout << "Warmer\n";
        }
        else if (diff <= 25) {
            std::cout << "Warm\n";
        }
        else if (diff <= 35) {
            std::cout << "Cold\n";
        }
        else if (diff <= 50) {
            std::cout << "Colder\n";
        }
        else {
            std::cout << "Freezing\n";
        }
    }

    return 0;
}
