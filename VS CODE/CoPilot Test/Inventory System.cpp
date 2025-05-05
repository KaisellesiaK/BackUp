#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Include the iomanip library

using namespace std;

struct Computer {
    int id;
    string externalComponents;
    string position;
    string status; // Add status field
};

vector<Computer> inventory;

void initializeInventory() {
    vector<string> components = {
        "Monitor, Keyboard, Mouse",
        "Monitor, Keyboard, Mouse, LAN Cable",
        "Monitor, Keyboard, Mouse, AVR"
    };

    vector<string> statuses = {
        "Good",
        "Bad",
        "Broken"
    };

    for (int i = 1; i <= 34; ++i) {
        Computer comp;
        comp.id = i;
        comp.externalComponents = components[i % components.size()];
        comp.position = "Position " + to_string(i);
        comp.status = statuses[i % statuses.size()]; // Set status
        inventory.push_back(comp);
    }
}

void addComputer() {
    if (inventory.size() >= 34) {
        cout << "Inventory is full. Cannot add more computers." << endl;
        return;
    }
    Computer comp;
    cout << "Enter Computer ID: ";
    cin >> comp.id;
    cout << "Enter External Components: ";
    cin.ignore();
    getline(cin, comp.externalComponents);
    cout << "Enter Position: ";
    getline(cin, comp.position);
    cout << "Enter Status (Good/Bad/Broken): ";
    getline(cin, comp.status);
    inventory.push_back(comp);
    cout << "Computer added successfully!" << endl;
}

void editComputer() {
    int id;
    cout << "Enter Computer ID to edit: ";
    cin >> id;
    for (auto &comp : inventory) {
        if (comp.id == id) {
            cout << "Enter new External Components: ";
            cin.ignore();
            getline(cin, comp.externalComponents);
            cout << "Enter new Position: ";
            getline(cin, comp.position);
            cout << "Enter new Status (Good/Bad/Broken): ";
            getline(cin, comp.status);
            cout << "Computer updated successfully!" << endl;
            return;
        }
    }
    cout << "Computer not found!" << endl;
}

void deleteComputer() {
    int id;
    cout << "Enter Computer ID to delete: ";
    cin >> id;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            inventory.erase(it);
            cout << "Computer deleted successfully!" << endl;
            return;
        }
    }
    cout << "Computer not found!" << endl;
}

void searchComputer() {
    int id;
    cout << "Enter Computer ID to search: ";
    cin >> id;
    for (const auto &comp : inventory) {
        if (comp.id == id) {
            cout << "Computer ID: " << comp.id << endl;
            cout << "External Components: " << comp.externalComponents << endl;
            cout << "Position: " << comp.position << endl;
            cout << "Status: " << comp.status << endl;
            return;
        }
    }
    cout << "Computer not found!" << endl;
}

void displayMenu() {
    cout << "1. Add Computer" << endl;
    cout << "2. Edit Computer" << endl;
    cout << "3. Delete Computer" << endl;
    cout << "4. Search Computer" << endl;
    cout << "5. Display Inventory Status" << endl; // Add menu option
    cout << "6. Exit" << endl;
}

void displayInventory() {
    cout << "Current Inventory:" << endl;
    int count = 0;
    for (const auto &comp : inventory) {
        cout << "+-----------------------------+" << endl;
        cout << "| ID: " << setw(2) << setfill('0') << comp.id << "                       |" << endl;
        cout << "| Ext: " << comp.externalComponents << " |" << endl;
        cout << "| Pos: " << comp.position << "           |" << endl;
        cout << "+-----------------------------+" << endl;
        count++;
        if (count % 5 == 0) {
            cout << endl;
        }
    }
    if (count % 5 != 0) {
        cout << endl;
    }
}

void displayInventoryTable() {
    cout << "+-------------+-------------+-------------+-------------+-------------+-------------+-------------+" << endl;
    cout << "| Current Inventory Table:                                                    |" << endl;
    cout << "+-------------+-------------+-------------+-------------+-------------+-------------+-------------+" << endl;
    int rows = 5;
    int cols = 7;
    int total = rows * cols;
    for (int i = 0; i < total; ++i) {
        if (i < inventory.size()) {
            cout << "|    PC" << setw(2) << setfill('0') << inventory[i].id << "    ";
        } else {
            cout << "|             ";
        }
        if ((i + 1) % cols == 0) {
            cout << "|" << endl;
            cout << "+-------------+-------------+-------------+-------------+-------------+-------------+-------------+" << endl;
        }
    }
}

void displayInventoryStatus() {
    cout << "Inventory Status:" << endl;
    for (const auto &comp : inventory) {
        cout << "+-----------------------------+" << endl;
        cout << "| ID: " << setw(2) << setfill('0') << comp.id << "                       |" << endl;
        cout << "| Status: " << setw(10) << left << comp.status << "           |" << endl;
        cout << "+-----------------------------+" << endl;
    }
}

int main() {
    initializeInventory();
    int choice;
    while (true) {
        displayInventoryTable();
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addComputer();
                break;
            case 2:
                editComputer();
                break;
            case 3:
                deleteComputer();
                break;
            case 4:
                searchComputer();
                break;
            case 5:
                displayInventoryStatus();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}