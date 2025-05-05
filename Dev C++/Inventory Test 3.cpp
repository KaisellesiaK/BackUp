#include <iostream>
#include <string>
#include <cstdlib> // for system cls
#include <ctime> 
#include <iomanip> // for UI mapping syntax setw
#include <conio.h>  // for _getch

using namespace std;

// Declare functions
void displayComponentGrid();
void displayMenu();

struct Component {
    string name;
    int quantity;
    string status;
};

class Unit {
public:
    Component components[7];  // Maximum of 7 components per unit
    int numComponents;        // Keeps track of how many components the unit has

    // Constructor to initialize with 5 automatic components
    Unit() {
        numComponents = 5;  // Start with 5 components

        // Initialize 5 automatic components
        components[0] = {"Mouse", 1, randomStatus()};
        components[1] = {"Keyboard", 1, randomStatus()};
        components[2] = {"AVR", 1, randomStatus()};
        components[3] = {"HDMI", 1, randomStatus()};
        components[4] = {"System Unit", 1, randomStatus()};

        // The remaining 2 components are uninitialized
    }

    // Method to generate a random status (Good or Bad)
    string randomStatus() {
        return (rand() % 5 == 0) ? "Bad!" : "Good";  // 5% chance of "Bad", 95% "Good"
    }

    // Method to add a new component, if there's space
    void addComponent() {
        if (numComponents >= 7) {
            cout << "         Cannot add more components. Maximum of 7 components per unit.\n";
            return;
        }

        string name, status;
        int quantity;
        system("cls");
        cout << "                                                 _________________________ \n";
    	cout << "                                                |  _____________________  |\n";
    	cout << "                                                |:|  ADD COMPONENT:____ |:|\n";
    	cout << "                                                |:|_____________________|:|\n";
    	cout << "                                                |_________________________|\n\n";
        cout << "         Enter component name: ";
        cin >> name;
        cout << "         Enter quantity: ";
        cin >> quantity;
        cout << "         Enter status (Good or Bad!): ";
        cin >> status;

        components[numComponents] = {name, quantity, status};
        numComponents++;

        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n                                                 _________________________ \n";
    	cout << "                                                |  _____________________  |\n";
    	cout << "                                                |:|   COMPONENT ADDED   |:|\n";
    	cout << "                                                |:|_____________________|:|\n";
    	cout << "                                                |_________________________|\n";
    }

    // Method to edit a component
    void editComponent(int componentIndex) {
       if (componentIndex < 0 || componentIndex >= numComponents) {
        	cout << "         Invalid component index.\n";
        	return;
   	 	}

    	string name, status;
    	int quantity;
    	
    	cout << "                                   _____________________________________________________\n";
    	cout << "                                  |  _________________________________________________  |\n";
    	cout << "                                  |:| Editing Component: " << left << setw(29) << components[componentIndex].name << "|:|\n";
    	cout << "                                  |:| Current name: " << left << setw(34) << components[componentIndex].name << "|:|\n";
    	cout << "                                  |:| Current quantity: " << left << setw(30) << components[componentIndex].quantity << "|:|\n";
    	cout << "                                  |:| Current status: " << left << setw(32) << components[componentIndex].status << "|:|\n";
    	cout << "                                  |:|_________________________________________________|:|\n";
    	cout << "                                  |_____________________________________________________|\n\n";

    // Now ask the user for new details
    	cout << "         Enter new name (leave blank to keep current): ";
    	cin.ignore();
    	getline(cin, name);  // Get full line input

    	if (name.empty()) {
       	 name = components[componentIndex].name;  // If no new name is entered, keep the old one
   	    }

    	cout << "         Enter new quantity (enter 0 to keep current): ";
    	cin >> quantity;
    	if (quantity == 0) {
       	 	quantity = components[componentIndex].quantity;  // Keep the old quantity if user enters 0
    	}

    	cout << "         Enter new status (Good or Bad): ";
    	cin >> status;

    	while (status != "Good" && status != "Bad") {
        	cout << "         Invalid input. Please enter 'Good' or 'Bad': ";
        	cin >> status;
    	}
    	
    	if (status.empty()) {
        	status = components[componentIndex].status;  // Keep the old status if no new status is entered
    	}

    // Update the component with the new details
    	components[componentIndex] = {name, quantity, status};

    	system("cls");

    // Print the updated UI
    	cout << "\n\n\n\n\n\n\n\n\n\n                                                 _________________________ \n";
   	    cout << "                                                |  _____________________  |\n";
    	cout << "                                                |:|  COMPONENT UPDATED  |:|\n";
    	cout << "                                                |:|_____________________|:|\n";
    	cout << "                                                |_________________________|\n";
    }

    // Method to delete a component
    void deleteComponent(int componentIndex) {
        if (componentIndex < 0 || componentIndex >= numComponents) {
            cout << "Invalid component index.\n";
            return;
        }

        // Move the subsequent components to fill the deleted one
        for (int i = componentIndex; i < numComponents - 1; ++i) {
            components[i] = components[i + 1];
        }

        numComponents--;
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n                                                 _________________________ \n";
    	cout << "                                                |  _____________________  |\n";
    	cout << "                                                |:| SUCCESSFULLY DELETE |:|\n";
    	cout << "                                                |:|_____________________|:|\n";
    	cout << "                                                |_________________________|\n";
    }

    // Method to display the details of the components in the unit
    void displayUnitDetails() {
        cout << "Unit components:\n";
        for (int i = 0; i < numComponents; ++i) {
            cout << "Component Name: " << components[i].name << endl;
            cout << "Quantity: " << components[i].quantity << endl;
            cout << "Status: " << components[i].status << endl;
            cout << "-----------------------------\n";
        }
    }

    // Function to display the components of this unit
    void displayComponents(int unitNo) {  // Pass unit number as parameter
        cout << "                                   ________________________________________________________\n";
    	cout << "                                  |  ____________________________________________________  |\n";
    	cout << "                                  |:|                      UNIT NO. " << setw(2) << setfill(' ') << unitNo << "                   |:|\n";
    	cout << "                                  |:|                   COMPUTER LAB 01                  |:|\n";
    	cout << "                                  |:|----------------------------------------------------|:|\n";
    	cout << "                                  |:|   COMPONENTS NAME  |    QUANTITY    |    STATUS    |:|\n";
    	cout << "                                  |:|----------------------------------------------------|:|\n";

    	for (int i = 0; i < numComponents; ++i) {
        	cout << "                                  |:|   " << left << setw(16) << components[i].name 
             	<< " |       " << setfill(' ') << setw(1) << components[i].quantity 
             	<< "        |     " << components[i].status << "     |:|\n";
    	}

    	cout << "                                  |:|____________________________________________________|:|\n";
    	cout << "                                  |________________________________________________________|\n\n";
    }
};

void invalidDisplay() {
	cout << "\n\n\n\n\n\n\n\n\n\n                                      __-----_---__-----__-_---_-__----_-__--_-__\n";
	cout << "                                     |  _______________________________________  |\n";
	cout << "                                     |:|           INVALID INPUTT!!!!!         |:|\n";
	cout << "                                     |:|   > Please select a valid option. <   |:|\n";
	cout << "                                     |:|_______________________________________|:|\n";
	cout << "                                     |__-_-_---___----__--_--__-_____----___--___|\n";
}

// Function to display the component grid
void displayComponentGrid() {
    cout << "                                                 _________________________ \n";
    cout << "                                                |  _____________________  |\n";
    cout << "                                                |:|  INVENTORY SYSTEM:  |:|\n";
    cout << "                                                |:|_____________________|:|\n";
    cout << "                                                |_________________________|\n";
    cout << "                           _________________________________________________________________________ \n";
    cout << "                          |  _____________________________________________________________________  |\n";
    cout << "                          |:| |                    COMPUTER LABORATORY 01 UNIT          [3] EXIT  |:|\n";
    cout << "                          |:|_|                                                                   |:|\n";
    cout << "                          |:|           +---------------------------------------------------------|:|\n";
    cout << "                          |:|           |   C01   |    C02    |    C03    |    C04    |    C05    |:|\n";
    cout << "                          |:|           +---------------------------------------------------------|:|\n";
    cout << "                          |:|_          |   C06   |    C07    |    C08    |    C09    |    C10    |:|\n";
    cout << "                          |:|_|         +---------------------------------------------------------|:|\n";
    cout << "                          |:|           |   C11   |    C12    |    C13    |    C14    |    C15    |:|\n";
    cout << "                          |:|_          +---------------------------------------------------------|:|\n";
    cout << "                          |:| |         |   C16   |    C17    |    C18    |    C19    |    C20    |:|\n";
    cout << "                          |:|_|_________|_________|___________|___________|___________|___________|:|\n";
    cout << "                          |_________________________________________________________________________|\n";
}

// Function to display the menu options
void displayMenu() {
    cout << "                                      +------------+       +--------------------------+ \n";
    cout << "                                      | [1] Search |       | [2] Display all Units    | \n";
    cout << "                                      +------------+       +--------------------------+ \n";
}

// Function to show the component options (Edit, Delete, Add, Back)
void showComponentOptions(Unit& unit) {
    int choice, componentChoice;

    cout << "                                +------------+  +------------+  +------------+  +------------+\n";
    cout << "                                | [1] ADD    |  | [2] EDIT   |  | [3] DELETE |  | [4] BACK   |\n";
    cout << "                                +------------+  +------------+  +------------+  +------------+\n";

    // Wait for a single key press
    choice = _getch();  // This is used from conio.h (Windows-specific)

    if (choice == '1' || choice == '2' || choice == '3' || choice == '4') {
        choice -= '0';  // Convert char to integer
    } else {
    	system("cls");
    	invalidDisplay();
        return;
    }

    switch (choice) {
        case 1:  // Add component
        	unit.addComponent();
            break;

        case 2:  // Edit component
        	system("cls");
        	cout << "                                                 _________________________ \n";
    		cout << "                                                |  _____________________  |\n";
    		cout << "                                                |:|  EDIT COMPONENT:___ |:|\n";
    		cout << "                                                |:|_____________________|:|\n";
    		cout << "                                                |_________________________|\n\n";
            cout << "         Enter component number (1 to 7) to edit: ";
            cin >> componentChoice;
            if (componentChoice >= 1 && componentChoice <= 7) {
                unit.editComponent(componentChoice - 1);  // -1 for 0-indexed
            } else {
                cout << "         Invalid component number.\n";
            }
            break;

        case 3:  // Delete component
        	system("cls");
        	cout << "                                                 _________________________ \n";
    		cout << "                                                |  _____________________  |\n";
    		cout << "                                                |:|  DELETE COMPONENT:_ |:|\n";
    		cout << "                                                |:|_____________________|:|\n";
    		cout << "                                                |_________________________|\n\n";
    		
        	cout << "         Enter component number (1 to 7) to delete: ";
            cin >> componentChoice;
            if (componentChoice >= 1 && componentChoice <= 7) {
                unit.deleteComponent(componentChoice - 1);  // -1 for 0-indexed
            } else {
                cout << "         Invalid component number.\n";
            }
            break;

        case 4:  // Back to main menu
            return;

        default:
        	invalidDisplay();
            break;
    }
}

// Main function
int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed for random number generation

    int choice, unitChoice;

    Unit units[20];  // Array to hold 20 units
    
    while (true) {
        system("cls");

        // Display grid and menu
        displayComponentGrid();
        displayMenu();

        // Wait for a user input (key press)
        choice = _getch();
        if (choice == '1' || choice == '2' || choice == '3') {
            choice -= '0';  // Convert char to integer
        } else {
        	system("cls");
    		invalidDisplay();
            continue;
        }

        switch (choice) {
            case 1:  // Search functionality
                system("cls");
                cout << "                                                 _________________________ \n";
    			cout << "                                                |  _____________________  |\n";
    			cout << "                                                |:|  SEARCH UNIT:_____  |:|\n";
    			cout << "                                                |:|_____________________|:|\n";
    			cout << "                                                |_________________________|\n\n";
                cout << "                                                Enter the unit number (1 to 20): ";
                cin >> unitChoice;
                if (unitChoice >= 1 && unitChoice <= 20) {
                    units[unitChoice - 1].displayComponents(unitChoice);  // Pass unitChoice instead of numComponents + 1
                    showComponentOptions(units[unitChoice - 1]);  // Display Edit/Delete/Add options
                } else {
                	system("cls");
    				invalidDisplay();
                }
                cout << "\nPress any key to return to the main page...";
                cin.ignore();
                cin.get();
                break;

            case 2:  // Display all units
                system("cls");
                cout << "                                                 _________________________\n";
                cout << "                                                |  _____________________  |\n";
                cout << "                                                |:|  DISPLAY ALL UNITS  |:|\n";
                cout << "                                                |:|_____________________|:|\n";
                cout << "                                                |_________________________|\n";
                cout << "                                          _______________________________________\n";
                cout << "                                         |  ___________________________________  |\n";
                cout << "                                         |:|            ALL UNIT LIST          |:|\n";
                cout << "                                         |:|           COMPUTER LAB 01         |:|\n";
                cout << "                                         |:|-----------------------------------|:|\n";
                cout << "                                         |:|   UNIT NO.   |       STATUS       |:|\n";
                cout << "                                         |:|--------------+--------------------|:|\n";
                for (int i = 0; i < 20; ++i) {
                    cout << "                                         |:|     C" << setw(2) << setfill('0') << (i + 1) << "      |        " << units[i].components[0].status << "        |:|\n";
                }
                cout << "                                         |:|___________________________________|:|\n";
                cout << "                                         |_______________________________________|\n";
                cout << "\nPress any key to return to the main page...";
                cin.ignore();
                cin.get();
                break;

            case 3:  // Exit
                cout << "Exiting the program.\n";
                return 0;
	
            default:
                cout << "\nInvalid selection. Please choose a valid option (1-3).\n";
                break;
        }
    }

    return 0;
}
