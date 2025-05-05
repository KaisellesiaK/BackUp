#include <iostream>
#include <cstring> // Include string.h for string functions
#include <iomanip> // Include iomanip for std::setw and std::left>
#include <limits>  // For numeric_limits
#include <cstdlib> // Include stdlib.h for system("cls") or system("clear")

using namespace std;

void clearScreen() {
    system("cls"); // Change to "clear" if you're on a Unix-based system
}

void waitForUser() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Wait for user input
    cin.get();
}

void printHeader(const string &title) {
    cout << "+----------------------------------------+" << endl;
    cout << "| " << setw(38) << left << title << "|" << endl;
    cout << "+----------------------------------------+" << endl;
}

void printFooter() {
    cout << "+----------------------------------------+" << endl;
}

void stringLength() {
    char str[100];
    printHeader("STRING LENGTH (strlen)");
    cout << "Enter a string to find its length: ";
    cin.ignore();
    cin.getline(str, 100);
    cout << "Length of the string is: " << strlen(str) << endl;
    printFooter();
    waitForUser();
}

void stringCopy() {
    char str1[100], str2[100];
    printHeader("STRING COPY (strcpy)");
    cout << "Enter a string to copy: ";
    cin.ignore();
    cin.getline(str2, 100);
    strcpy(str1, str2);
    cout << "Copied string: " << str1 << endl;
    printFooter();
    waitForUser();
}

void stringConcatenate() {
    char str1[100], str2[100];
    printHeader("STRING CONCATENATION (strcat)");
    cout << "Enter the first string: ";
    cin.ignore();
    cin.getline(str1, 100);
    cout << "Enter the second string to concatenate: ";
    cin.getline(str2, 100);
    strcat(str1, str2);
    cout << "Concatenated string: " << str1 << endl;
    printFooter();
    waitForUser();
}

void stringCompare() {
    char str1[100], str2[100];
    printHeader("STRING COMPARISON (strcmp)");
    cout << "Enter the first string: ";
    cin.ignore();
    cin.getline(str1, 100);
    cout << "Enter the second string: ";
    cin.getline(str2, 100);
    int cmpResult = strcmp(str1, str2);
    if (cmpResult == 0)
        cout << "Strings are equal." << endl;
    else if (cmpResult < 0)
        cout << "String 1 is less than String 2." << endl;
    else
        cout << "String 1 is greater than String 2." << endl;
    printFooter();
    waitForUser();
}

void stringToLower() {
    char str[100];
    printHeader("STRING TO LOWERCASE (strlwr)");
    cout << "Enter a string to convert to lowercase: ";
    cin.ignore();
    cin.getline(str, 100);
    for (int i = 0; str[i]; i++) str[i] = tolower(str[i]); // Manual lowercase conversion
    cout << "Lowercase string: " << str << endl;
    printFooter();
    waitForUser();
}

void stringToUpper() {
    char str[100];
    printHeader("STRING TO UPPERCASE (strupr)");
    cout << "Enter a string to convert to uppercase: ";
    cin.ignore();
    cin.getline(str, 100);
    for (int i = 0; str[i]; i++) str[i] = toupper(str[i]); // Manual uppercase conversion
    cout << "Uppercase string: " << str << endl;
    printFooter();
    waitForUser();
}

void stringReverse() {
    char str[100];
    printHeader("STRING REVERSAL (strrev)");
    cout << "Enter a string to reverse: ";
    cin.ignore();
    cin.getline(str, 100);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) swap(str[i], str[len - i - 1]); // Manual reverse
    cout << "Reversed string: " << str << endl;
    printFooter();
    waitForUser();
}

void displayMenu() {
    cout << "+----------------------------------------+" << endl;
    cout << "|           STRING FUNCTIONS MENU        |" << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "| 1. String Length (strlen)              |" << endl;
    cout << "| 2. String Copy (strcpy)                |" << endl;
    cout << "| 3. String Concatenation (strcat)       |" << endl;
    cout << "| 4. String Comparison (strcmp)          |" << endl;
    cout << "| 5. String to Lowercase (strlwr)        |" << endl;
    cout << "| 6. String to Uppercase (strupr)        |" << endl;
    cout << "| 7. String Reversal (strrev)            |" << endl;
    cout << "| 8. Exit                                |" << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        clearScreen(); // Clear the screen before displaying the menu
        displayMenu();
        cin >> choice;

        // Error handling for invalid input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
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
