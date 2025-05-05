#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Computer {
    int id;
    string externalComponents;
    string position;
};

vector<Computer> inventory;

void initializeInventory() {
    for (int i = 1; i <= 34; ++i) {
        Computer comp;
        comp.id = i;
        comp.externalComponents = "External Component " + to_string(i);
        comp.position = "Position " + to_string(i);
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
    cout << "5. Exit" << endl;
}

void displayInventory() {
    cout << "Current Inventory:" << endl;
    for (const auto &comp : inventory) {
        cout << "ID: " << comp.id << ", External Components: " << comp.externalComponents << ", Position: " << comp.position << endl;
    }
}

int main() {
    initializeInventory();
    int choice;
    while (true) {
        displayInventory();
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
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
