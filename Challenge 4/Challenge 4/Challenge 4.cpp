// Challenge 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::string text;

    while (true)
    {
        std::cout << "Please enter a sentence: ";

        std::getline(std::cin, text);

        if (text.empty()) {
            std::cerr << "[!] ERROR: You have entered an empty string\n";
            continue;
        }

        std::string tabulated = "";
        tabulated += "|";

        for (char c : text) {
            tabulated += " ";
            tabulated += c;
            tabulated += " |";
        }

        std::string border = "";
        border.resize(tabulated.size());

        bool toggle = false;

        for (size_t i = 0; i < tabulated.size(); i++) {

            if (tabulated[i] == '|') {
                border[i] = '+';
            }
            else {
                border[i] = toggle ? '=' : '-';
                toggle = !toggle;
            }
        }

        std::cout << border << "\n";
        std::cout << tabulated << "\n";
        std::cout << border << "\n\n";
    }

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
