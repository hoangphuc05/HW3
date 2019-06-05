/*#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>
#include "readint.h"

using namespace std;

int main()
{
    int inputHigh, inputLow;
    try {
        cout << "Enter the range of values to read.\n";
        cout << "high: ";
        cin >> inputHigh;
        cout << "low: ";
        cin >> inputLow;
    }
    catch (ios_base::failure& ex) {
            cout << "Bad string, try again!\n";
            //reset the flag
            cin.clear();
            //skip the current input
            cin.ignore(numeric_limits<int>::max(), '\n');
    }
    try {
       
        int number = read_int("Please enter a number within the range: ", inputLow, inputHigh);
        cout << "You entered " << number << endl;
    }
    catch (invalid_argument &e) {
        cerr << "Exception: You supplied an invalid argument for read_int!\n";
    }
    
}*/
