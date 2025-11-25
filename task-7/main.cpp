#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Item {
    std::string name;
    std::string type;
    int price;
    int damage;
    std::string role;
};

struct Player {
    std::string name;
    std::string weapon;
    std::string role;
    int damage;
};

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    const std::vector<Item> initialItems = {
        {"Great Sword", "Sword", 40, 100, "Knight"},
        {"Scimitar", "Sword", 35, 75, "Knight"},
        {"Dagger", "Sword", 10, 35, "Knight"},
        {"Longbow", "Bow", 20, 55, "Archer"},
        {"Crossbow", "Bow", 40, 100, "Archer"},
        {"Rusty spear", "Spear", 10, 35, "Spearman"},
        {"Iron spear", "Spear", 20, 65, "Spearman"}
    };

    std::vector<Player> players(3);

    for (int i = 0; i < 3; i++) {
        std::cout << "Enter player #" << (i + 1) << "'s name: ";
        std::getline(std::cin, players[i].name);
    }

    bool confirmed = false;

    while (!confirmed) {
        int coins = 100;
        std::vector<Item> items = initialItems;

        std::cout << ">> Welcome "
            << players[0].name << ", "
            << players[1].name << " and "
            << players[2].name << " to the shop!\n";

        for (int p = 0; p < 3; p++) {

            while (true) {
                std::cout << ">> You currently have " << coins << " coins. You can buy the following items:\n";

                for (size_t i = 0; i < items.size(); i++) {
                    std::cout << ">> " << (i + 1) << ". " << items[i].name
                        << " [" << items[i].price << " coins, "
                        << items[i].damage << " damage]\n";
                }

                std::cout << "- Player " << (p + 1)
                    << ", please enter a weapon to buy: ";

                int choice;
                if (!(std::cin >> choice)) {
                    std::cout << "[!] ERROR: Please enter a valid number.\n";
                    clearInput();
                    continue;
                }

                clearInput();

                if (choice < 1 || choice >(int)items.size()) {
                    std::cout << "[!] ERROR: Please choose a valid item number.\n";
                    continue;
                }

                Item selected = items[choice - 1];

                if (selected.price > coins) {
                    std::cout << "[!] ERROR: Not enough coins, the " << selected.name
                        << " is " << selected.price << " coins and there are only "
                        << coins << " available for use!\n";
                    continue;
                }

                coins -= selected.price;
                players[p].weapon = selected.name;
                players[p].damage = selected.damage;
                players[p].role = selected.role;

                std::cout << ">> " << players[p].name << " bought a "
                    << selected.name << " for "
                    << selected.price << " coins. The party now has "
                    << coins << " coins.\n";

                items.erase(items.begin() + (choice - 1));
                break;
            }
        }

        std::string answer;
        std::cout << ">> Are you happy with your selection of weapons? (yes/no): ";
        std::getline(std::cin, answer);

        if (answer == "yes")
            confirmed = true;
        else
            std::cout << "-------------------------------------------\n";
    }

    std::cout << ">> The party:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << ">> - Player " << (i + 1) << " (" << players[i].name
            << "), Role: " << players[i].role
            << ", Weapon: " << players[i].weapon
            << ", Damage: " << players[i].damage
            << ".\n";
    }

    std::cout << ">> You are situated in a forest. A monster appears...\n";

    return 0;
}
