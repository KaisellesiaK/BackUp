#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits> // for input validation

using namespace std;

// Component structure
struct Component {
    string name;
    int quantity;
    string status;
};

// Unit class to manage components
class Unit {
private:
    static const int MAX_COMPONENTS = 7;
    Component components[MAX_COMPONENTS];
    int numComponents;

public:
    // Constructor
    Unit() {
        numComponents = 5;  // Start with 5 default components
        
        // Initialize default components with numbers
        components[0] = {"Mouse-1", 1, randomStatus()};
        components[1] = {"Keyboard-2", 1, randomStatus()};
        components[2] = {"AVR-3", 1, randomStatus()};
        components[3] = {"HDMI-4", 1, randomStatus()};
        components[4] = {"System Unit-5", 1, randomStatus()};
    }
    
    // Generate random status
    string randomStatus() {
        return (rand() % 5 == 0) ? "Bad!" : "Good";
    }
    
    // Display components of this unit
    void displayComponents(int unitNo) {
        cout << "\n---------------- UNIT " << unitNo << " ----------------\n";
        cout << "COMPUTER LAB 01\n";
        cout << "----------------------------------------\n";
        cout << left << setw(20) << "COMPONENT NAME" << setw(15) << "QUANTITY" << "STATUS\n";
        cout << "----------------------------------------\n";
        
        for (int i = 0; i < numComponents; i++) {
            cout << left << setw(20) << components[i].name 
                 << setw(15) << components[i].quantity 
                 << components[i].status << endl;
        }
        cout << "----------------------------------------\n";
    }
    
    // Add a new component
    void addComponent() {
        if (numComponents >= MAX_COMPONENTS) {
            cout << "Cannot add more components. Maximum limit reached.\n";
            return;
        }
        
        string name;
        int quantity;
        string status;
        
        clearScreen();
        cout << "\n----- ADD NEW COMPONENT -----\n";
        
        cout << "Enter component name: ";
        cin >> name;
        
        // Add number to component name
        name = name + "-" + to_string(numComponents + 1);
        
        cout << "Enter quantity: ";
        cin >> quantity;
        while (cin.fail() || quantity <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a positive number: ";
            cin >> quantity;
        }
        
        cout << "Enter status (Good or Bad!): ";
        cin >> status;
        while (status != "Good" && status != "Bad!") {
            cout << "Invalid status. Enter 'Good' or 'Bad!': ";
            cin >> status;
        }
        
        components[numComponents] = {name, quantity, status};
        numComponents++;
        
        cout << "\nComponent added successfully!\n";
    }
    
    // Edit an existing component
    void editComponent(int index) {
        if (index < 0 || index >= numComponents) {
            cout << "Invalid component selection.\n";
            return;
        }
        
        string name, status;
        int quantity;
        string componentNumber = components[index].name.substr(components[index].name.find("-"));
        
        clearScreen();
        cout << "\n----- EDIT COMPONENT -----\n";
        cout << "Current component: " << components[index].name << endl;
        cout << "Current quantity: " << components[index].quantity << endl;
        cout << "Current status: " << components[index].status << endl;
        cout << "----------------------------\n";
        
        cout << "Enter new name (or press Enter to keep current): ";
        cin.ignore();
        getline(cin, name);
        
        if (!name.empty()) {
            // Preserve the component number
            components[index].name = name + componentNumber;
        }
        
        cout << "Enter new quantity (or 0 to keep current): ";
        cin >> quantity;
        if (quantity > 0) {
            components[index].quantity = quantity;
        }
        
        cout << "Enter new status (Good or Bad!): ";
        cin >> status;
        if (status == "Good" || status == "Bad!") {
            components[index].status = status;
        }
        
        cout << "\nComponent updated successfully!\n";
    }
    
    // Delete a component
    void deleteComponent(int index) {
        if (index < 0 || index >= numComponents) {
            cout << "Invalid component selection.\n";
            return;
        }
        
        // Shift components to fill the gap
        for (int i = index; i < numComponents - 1; i++) {
            components[i] = components[i + 1];
            
            // Update the component number in the name
            size_t pos = components[i].name.find("-");
            if (pos != string::npos) {
                string baseName = components[i].name.substr(0, pos);
                components[i].name = baseName + "-" + to_string(i + 1);
            }
        }
        
        numComponents--;
        cout << "\nComponent deleted successfully!\n";
    }
    
    // Get the status of the first component (for display all units)
    string getMainStatus() const {
        if (numComponents > 0) {
            return components[0].status;
        }
        return "Unknown";
    }
    
private:
    // Helper function to clear screen (platform-independent)
    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
};

// Helper function to clear screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to display the main menu
void displayMainMenu() {
    cout << "\n======== COMPUTER LAB INVENTORY SYSTEM ========\n";
    cout << "1. Search Unit\n";
    cout << "2. Display All Units\n";
    cout << "3. Exit\n";
    cout << "=============================================\n";
    cout << "Enter your choice: ";
}

// Function to display the unit menu
void displayUnitMenu() {
    cout << "\n---- UNIT OPTIONS ----\n";
    cout << "1. Add Component\n";
    cout << "2. Edit Component\n";
    cout << "3. Delete Component\n";
    cout << "4. Back to Main Menu\n";
    cout << "---------------------\n";
    cout << "Enter your choice: ";
}

// Function to display the component grid for 34 computers
void displayComponentGrid() {
    cout << "\n======== COMPUTER LABORATORY 01 UNIT LAYOUT (34 UNITS) ========\n";
    cout << "+-------+-------+-------+-------+-------+-------+-------+\n";
    cout << "|  C01  |  C02  |  C03  |  C04  |  C05  |  C06  |  C07  |\n";
    cout << "+-------+-------+-------+-------+-------+-------+-------+\n";
    cout << "|  C08  |  C09  |  C10  |  C11  |  C12  |  C13  |  C14  |\n";
    cout << "+-------+-------+-------+-------+-------+-------+-------+\n";
    cout << "|  C15  |  C16  |  C17  |  C18  |  C19  |  C20  |  C21  |\n";
    cout << "+-------+-------+-------+-------+-------+-------+-------+\n";
    cout << "|  C22  |  C23  |  C24  |  C25  |  C26  |  C27  |  C28  |\n";
    cout << "+-------+-------+-------+-------+-------+-------+-------+\n";
    cout << "|  C29  |  C30  |  C31  |  C32  |  C33  |  C34  |       |\n";
    cout << "+-------+-------+-------+-------+-------+-------+-------+\n";
}

// Function to wait for user input
void waitForInput() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Main function
int main() {
    // Seed random number generator
    srand(static_cast<unsigned>(time(0)));
    
    // Create array of units
    const int NUM_UNITS = 34;
    Unit units[NUM_UNITS];
    
    int choice, unitChoice, componentChoice;
    
    while (true) {
        clearScreen();
        displayComponentGrid();
        displayMainMenu();
        
        cin >> choice;
        
        switch (choice) {
            case 1: // Search for a specific unit
                clearScreen();
                cout << "\n----- SEARCH UNIT -----\n";
                cout << "Enter unit number (1-34): ";
                cin >> unitChoice;
                
                if (unitChoice >= 1 && unitChoice <= NUM_UNITS) {
                    clearScreen();
                    units[unitChoice - 1].displayComponents(unitChoice);
                    
                    do {
                        displayUnitMenu();
                        cin >> choice;
                        
                        switch (choice) {
                            case 1: // Add component
                                units[unitChoice - 1].addComponent();
                                break;
                                
                            case 2: // Edit component
                                cout << "\nEnter component number to edit (1-7): ";
                                cin >> componentChoice;
                                units[unitChoice - 1].editComponent(componentChoice - 1);
                                break;
                                
                            case 3: // Delete component
                                cout << "\nEnter component number to delete (1-7): ";
                                cin >> componentChoice;
                                units[unitChoice - 1].deleteComponent(componentChoice - 1);
                                break;
                                
                            case 4: // Back to main menu
                                break;
                                
                            default:
                                cout << "\nInvalid choice. Please try again.\n";
                        }
                        
                        if (choice != 4) {
                            waitForInput();
                            clearScreen();
                            units[unitChoice - 1].displayComponents(unitChoice);
                        }
                    } while (choice != 4);
                } else {
                    cout << "\nInvalid unit number. Please enter a number between 1 and 34.\n";
                    waitForInput();
                }
                break;
                
            case 2: // Display all units
                clearScreen();
                cout << "\n----- ALL UNITS STATUS -----\n";
                cout << "----------------------------\n";
                cout << left << setw(15) << "UNIT NUMBER" << "STATUS\n";
                cout << "----------------------------\n";
                
                for (int i = 0; i < NUM_UNITS; i++) {
                    cout << left << setw(15) << "C" + to_string(i + 1) << units[i].getMainStatus() << endl;
                }
                
                waitForInput();
                break;
                
            case 3: // Exit the program
                cout << "\nThank you for using the Computer Lab Inventory System. Goodbye!\n";
                return 0;
                
            default:
                cout << "\nInvalid choice. Please try again.\n";
                waitForInput();
        }
    }
    
    return 0;
}
