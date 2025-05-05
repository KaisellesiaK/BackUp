#include <iostream>

using namespace std;

int main() {
    double centimeters, millimeters, meters;

    cout << "Enter length in centimeters: ";
    cin >> centimeters;

    millimeters = centimeters * 10;
    meters = centimeters / 100;

    cout << centimeters << " cm is equal to " << millimeters << " mm and " << meters << " m." << endl;

    return 0;
}
