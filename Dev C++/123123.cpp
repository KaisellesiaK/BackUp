#include <iostream>
#include <cmath> // For sqrt() and pow()
#include <iomanip> // For formatting output

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "+----------------------------------------+" << endl;
    cout << "|       QUADRATIC EQUATION SOLVER        |" << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "| 1. Solve a quadratic equation          |" << endl;
    cout << "| 2. Exit                                |" << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "Enter your choice: ";
}

// Function to solve the quadratic equation
void solveQuadraticEquation() {
    // Declare variables
    double a, b, c, discriminant, x1, x2, realPart, imaginaryPart;

    // User input for coefficients
    cout << "\nEnter the coefficient a: ";
    cin >> a;

    // Check if 'a' is zero (not a quadratic equation)
    if (a == 0) {
        cout << "Coefficient 'a' cannot be zero. This is not a quadratic equation.\n";
        return;
    }

    cout << "Enter the coefficient b: ";
    cin >> b;
    cout << "Enter the coefficient c: ";
    cin >> c;

    // Compute the discriminant
    discriminant = pow(b, 2) - 4 * a * c;

    // Explain the discriminant value
    cout << "\n----------------------------------------\n";
    cout << "Explanation:\n";
    cout << "----------------------------------------\n";
    cout << "The quadratic equation is: " << a << "x^2 + " << b << "x + " << c << " = 0\n";
    cout << "The discriminant (D) is calculated as: D = b^2 - 4ac\n";
    cout << "Substituting the values: D = (" << b << ")^2 - 4 * (" << a << ") * (" << c << ")\n";
    cout << "D = " << discriminant << "\n";

    // Check the discriminant value and compute roots
    cout << "\n----------------------------------------\n";
    cout << "Results:\n";
    cout << "----------------------------------------\n";

    if (discriminant > 0) {
        // Two real and distinct roots
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "The discriminant (D = " << discriminant << ") is greater than 0.\n";
        cout << "This means the equation has two real and distinct roots.\n";
        cout << "The parabola intersects the x-axis at two points.\n\n";
        cout << "x1 = " << fixed << setprecision(2) << x1 << endl;
        cout << "x2 = " << fixed << setprecision(2) << x2 << endl;
    } else if (discriminant == 0) {
        // One real root
        x1 = -b / (2 * a);
        cout << "The discriminant (D = " << discriminant << ") is equal to 0.\n";
        cout << "This means the equation has one real root (a repeated root).\n";
        cout << "The parabola touches the x-axis at one point.\n\n";
        cout << "x1 = x2 = " << fixed << setprecision(2) << x1 << endl;
    } else {
        // Complex roots
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "The discriminant (D = " << discriminant << ") is less than 0.\n";
        cout << "This means the equation has complex roots.\n";
        cout << "The parabola does not intersect the x-axis.\n\n";
        cout << "x1 = " << fixed << setprecision(2) << realPart << " + " << imaginaryPart << "i\n";
        cout << "x2 = " << fixed << setprecision(2) << realPart << " - " << imaginaryPart << "i\n";
    }
    cout << "----------------------------------------\n";
}

int main() {
    int choice;

    do {
        // Display the menu
        displayMenu();
        cin >> choice;

        // Handle menu choices
        switch (choice) {
            case 1:
                solveQuadraticEquation();
                break;
            case 2:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1 or 2.\n";
        }

        // Add a pause before returning to the menu
        if (choice != 2) {
            cout << "\nPress Enter to return to the menu...";
            cin.clear(); // Clear any error flags
            cin.ignore(1000, '\n'); // Clear up to 1000 characters from the input buffer
            cin.get(); // Wait for Enter
        }
    } while (choice != 2);

    return 0;
}
