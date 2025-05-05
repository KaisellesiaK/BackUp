#include <iostream>
#include <cstring> // For string functions like strlen, strcpy, strcat, strcmp
#include <cstdlib> // For system("cls") to clear the screen
#include <limits>  // For numeric_limits to handle input

using namespace std;

// Clears the screen
void clearScreen() {
    system("cls"); // Use "clear" if you're on a Unix-based system
}

// Waits for the user to press Enter7
void waitForUser() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Displays the menu for the user
void displayMenu() {
    cout << "\t\t\t\t\t\t\t\t+----------------------------------------+" << endl;
    cout << "\t\t\t\t\t\t\t\t|           STRING FUNCTIONS MENU        |" << endl;
    cout << "\t\t\t\t\t\t\t\t+----------------------------------------+" << endl;
    cout << "\t\t\t\t\t\t\t\t| 1. String Length (strlen)              |" << endl;
    cout << "\t\t\t\t\t\t\t\t| 2. String Copy (strcpy)                |" << endl;
    cout << "\t\t\t\t\t\t\t\t| 3. String Concatenation (strcat)       |" << endl;
    cout << "\t\t\t\t\t\t\t\t| 4. String Comparison (strcmp)          |" << endl;
    cout << "\t\t\t\t\t\t\t\t| 5. String to Lowercase                 |" << endl;
    cout << "\t\t\t\t\t\t\t\t| 6. String to Uppercase                 |" << endl;
    cout << "\t\t\t\t\t\t\t\t| 7. String Reversal                     |" << endl;
    cout << "\t\t\t\t\t\t\t\t| 8. Exit                                |" << endl;
    cout << "\t\t\t\t\t\t\t\t+----------------------------------------+" << endl;
    cout << "\n\n\n\n\n\nEnter your choice: ";
}

// Finds the length of a string
void stringLength() {
    char str[100];
    cout << "Enter a string: ";
    cin.ignore();
    cin.getline(str, 100);
    cout << "Length of the string: " << strlen(str) << endl;
    waitForUser();
}

// Copies one string to another
void stringCopy() {
    char str1[100], str2[100];
    cout << "Enter a string to copy: ";
    cin.ignore();
    cin.getline(str2, 100);
    strcpy(str1, str2);
    cout << "Copied string: " << str1 << endl;
    waitForUser();
}

// Concatenates two strings
void stringConcatenate() {
    char str1[100], str2[100];
    cout << "Enter the first string: ";
    cin.ignore();
    cin.getline(str1, 100);
    cout << "Enter the second string: ";
    cin.getline(str2, 100);
    strcat(str1, str2);
    cout << "Concatenated string: " << str1 << endl;
    waitForUser();
}

// Compares two strings
void stringCompare() {
    char str1[100], str2[100];
    cout << "Enter the first string: ";
    cin.ignore();
    cin.getline(str1, 100);
    cout << "Enter the second string: ";
    cin.getline(str2, 100);
    int result = strcmp(str1, str2);
    if (result == 0)
        cout << "Strings are equal." << endl;
    else if (result < 0)
        cout << "String 1 is less than String 2." << endl;
    else
        cout << "String 1 is greater than String 2." << endl;
    waitForUser();
}

// Converts a string to lowercase
void stringToLower() {
    char str[100];
    cout << "Enter a string to convert to lowercase: ";
    cin.ignore();
    cin.getline(str, 100);
    for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
    cout << "Lowercase string: " << str << endl;
    waitForUser();
}

// Converts a string to uppercase
void stringToUpper() {
    char str[100];
    cout << "Enter a string to convert to uppercase: ";
    cin.ignore();
    cin.getline(str, 100);
    for (int i = 0; str[i]; i++) str[i] = toupper(str[i]);
    cout << "Uppercase string: " << str << endl;
    waitForUser();
}

// Reverses a string
void stringReverse() {
    char str[100];
    cout << "Enter a string to reverse: ";
    cin.ignore();
    cin.getline(str, 100);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) swap(str[i], str[len - i - 1]);
    cout << "Reversed string: " << str << endl;
    waitForUser();
}

// Main function to run the program
int main() {
    int choice;
    do {
        clearScreen(); // Clear the screen before displaying the menu
        displayMenu();
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 8." << endl;
            waitForUser();
            continue;
        }

        clearScreen(); // Clear the screen before executing the selected function
        switch (choice) {
            case 1:
                stringLength();
                break;
            case 2:
                stringCopy();
                break;
            case 3:
                stringConcatenate();
                break;
            case 4:
                stringCompare();
                break;
            case 5:
                stringToLower();
                break;
            case 6:
                stringToUpper();
                break;
            case 7:
                stringReverse();
                break;
            case 8:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
                waitForUser();
        }
    } while (choice != 8);

    return 0;
}
