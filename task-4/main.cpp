#include <iostream>

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