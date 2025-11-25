#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Item {
    int id;
    string name;
};

class InventorySystem {
private:
    vector<int> inventory;
    vector<Item> items;

public:
    InventorySystem() {
        items.push_back({ 0, "Empty" });
        items.push_back({ 1, "Shield" });
        items.push_back({ 2, "Potion" });
        items.push_back({ 3, "Gloves" });
    }

    void start() {
        while (true) {
            int size;
            cout << "Please enter an inventory size : ";
            cin >> size;

            if (size >= 1 && size <= 16) {
                inventory.assign(size, 0);
                cout << ">> Initialised inventory with " << size << " slots.\n";
                cout << ">> Type \"help\" for a list of all commands.\n";
                break;
            }
            else {
                cout << "[!] ERROR: Invalid inventory size (1-16 slots).\n";
            }
        }

        commandLoop();
    }

    void commandLoop() {
        string command;

        while (true) {
            cout << "- ";
            cin >> command;

            if (command == "help") {
                printHelp();
            }
            else if (command == "items") {
                listItems();
            }
            else if (command == "view") {
                int index;
                if (!(cin >> index)) invalidInput();
                viewSlot(index);
            }
            else if (command == "show_all") {
                showAll();
            }
            else if (command == "set") {
                int index, itemid;
                if (!(cin >> index >> itemid)) invalidInput();
                setSlot(index, itemid);
            }
            else if (command == "search_item") {
                string str;
                cin >> str;
                searchItem(str);
            }
            else if (command == "clear") {
                clear();
            }
            else if (command == "restart") {
                cout << ">> Cleared inventory.\n";
                start();
                return;
            }
            else if (command == "exit") {
                cout << ">> Exiting.\n";
                return;
            }
            else {
                cout << "[!] ERROR: Unknown command.\n";
            }
        }
    }

    void printHelp() {
        cout << ">> view <index>: Prints out details of the item.\n";
        cout << ">> show_all: Shows all inventory slots.\n";
        cout << ">> set <index> <itemid>: Sets slot to item.\n";
        cout << ">> search_item <str>: Searches for items containing str.\n";
        cout << ">> items: Shows all items.\n";
        cout << ">> exit: Exits the tool.\n";
        cout << ">> restart: Restarts the session.\n";
        cout << ">> help: Shows this list.\n";
        cout << ">> clear: Clears the inventory.\n";
    }

    void listItems() {
        for (auto& i : items)
            cout << ">> " << i.id << ": " << i.name << "\n";
    }

    void viewSlot(int index) {
        if (!validSlot(index)) {
            cout << "[!] ERROR: Invalid slot index.\n";
            return;
        }
        cout << ">> Inventory slot " << index << " details:\n";
        cout << ">> Name: " << getItemName(inventory[index]) << "\n";
    }

    void showAll() {
        cout << ">> Inventory:\n";
        for (size_t i = 0; i < inventory.size(); i++)
            cout << ">> - Slot " << i << ": " << getItemName(inventory[i]) << "\n";
    }

    void setSlot(int index, int itemid) {
        if (!validSlot(index)) {
            cout << "[!] ERROR: Invalid slot index.\n";
            return;
        }
        if (!validItem(itemid)) {
            cout << "[!] ERROR: Invalid item index.\n";
            return;
        }
        inventory[index] = itemid;
    }

    void searchItem(const string& str) {
        cout << ">> Search results:\n";
        for (auto& i : items) {
            if (i.name.find(str) != string::npos)
                cout << ">> - Item index " << i.id << ": " << i.name << "\n";
        }
    }

    void clear() {
        fill(inventory.begin(), inventory.end(), 0);
        cout << ">> Cleared inventory\n";
    }

    bool validSlot(int index) {
        return index >= 0 && index < (int)inventory.size();
    }

    bool validItem(int id) {
        return id >= 0 && id < (int)items.size();
    }

    string getItemName(int id) {
        if (validItem(id)) return items[id].name;
        return "Unknown";
    }

    void invalidInput() {
        cout << "[!] ERROR: Invalid input.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
};

int main() {
    InventorySystem system;
    system.start();
    return 0;
}
