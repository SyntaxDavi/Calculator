#include <iostream>     
#include <cstdlib>     
#include <iomanip>     
#include <chrono>       
#include <thread>      

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

float add(int a, int b) {
    return a + b;
}

float subtract(int a, int b) {
    return a - b;
}

float multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    return (b != 0) ? static_cast<double>(a) / b : (cout << "Cannot divide by 0\n", 0.0);
}

void menu() {

    int choice{ 0 };     // Stores user choice
    string option;       // To check if user wants to repeat
    int a, b;            // Operands for calculation

    do {
        sleep_for(milliseconds(250));

        // Display menu
        cout << "===========================================" << endl;
        cout << " Welcome to the C++ Calculator" << endl;
        cout << endl;
        cout << "\t1- To add." << endl;
        cout << "\t2- To subtract." << endl;
        cout << "\t3- To multiply." << endl;
        cout << "\t4- To divide." << endl;
        cout << endl;
        cout << "===========================================" << endl;
        cout << ">";
        cin >> choice;

        // Validate input
        while (choice < 1 || choice > 4) {
            cout << "Invalid option, please try again: " << endl;
            cin >> choice;
        }

        // Get numbers from user
        sleep_for(milliseconds(500));
        cout << "Enter the first number: " << endl;
        cin >> a;
        cout << "Enter the second number: " << endl;
        cin >> b;
        cout << endl;

        // Perform the operation based on user choice
        switch (choice) {
        case 1:
            cout << "Result of addition: " << add(a, b) << endl;
            break;
        case 2:
            cout << "Result of subtraction: " << subtract(a, b) << endl;
            break;
        case 3:
            cout << "Result of multiplication: " << multiply(a, b) << endl;
            break;
        case 4:
            cout << "Result of division: " << divide(a, b) << endl;
            break;
        default:
            cout << "Invalid option." << endl;
        }

        // Ask if user wants to calculate again
        sleep_for(milliseconds(500));
        cout << endl;
        cout << "Do you want to calculate again?" << endl;
        cout << "Type 'yes' to continue or any other key to exit: " << endl;
        cout << ">";
        cin >> option;

        sleep_for(milliseconds(500));

        // Clear screen depending on OS
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

    } while (option == "yes");

}

int main() {
    menu();
    return 0;
}
