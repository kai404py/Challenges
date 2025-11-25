#include <iostream>
#include <string>

int needed_ep(int curret_ep)
{
    int xp_into_level = curret_ep % 100;
    int needed = 100 - xp_into_level;
    if (needed == 100) needed = 0;
    return needed;
}

int main(int argc, const char* argv[]) {
    std::string name;
    std::string username;
    std::string clan;
    int ep;

    std::cout << "Name: ";
    std::cin >> name;

    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "Clan: ";
    std::cin >> clan;

    std::cout << "Exp level: ";

    while (!(std::cin >> ep)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid Number\n";
        std::cout << "Exp level: " << std::endl;
    }

    int level = ep / 100;
    int next_level = level + 1;
    int need = needed_ep(ep);

    std::cout << "\nYour name is " << name << " and your in-game name is [" << clan << "]" << username << "\n";
    std::cout << "You are currently level " << level << "\n";
    std::cout << "You need " << need << " to reach level " << next_level << "\n";
    return 0;
}