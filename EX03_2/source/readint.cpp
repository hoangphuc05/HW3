#include "readint.h"

#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <limits>

using namespace std;

int read_int(const string &prompt, int low, int high)

{

    cin.exceptions(ios_base::failbit | ios_base::badbit);
    int num = 0;
    while (true){
        try {
            if (low >= high) throw invalid_argument("Empty range!");
            cout << prompt;
            cin >> num;
            //cout << "input is: " << num << endl;
            if (num  >= high or num <= low) throw out_of_range("Number input is not in the range!");
            return num;
        } catch (ios_base::failure &ex) {
            cout << "Invalid input!\n";
            //reset the flag
            cin.clear();
            //skip the current input
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
        catch (out_of_range& e) {
            cout << "Your number is out of range!\n";
            //reset the flag
            //cin.clear();
            //skip the current input
            //cin.ignore(numeric_limits<int>::max(), '\n');
        }
        catch (exception &ex) {
            cout << "Invalid input! Exception\n";
            //reset the flag
            cin.clear();
            //skip the current input
            cin.ignore(numeric_limits<int>::max(), '\n');
        }

    }

}