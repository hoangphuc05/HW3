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
            if (num  > high or num < low) throw string("over sized!");
            else return num;
        } catch (ios_base::failure &ex) {
            cout << "Bad String!\n";
            //reset the flag
            cin.clear();
            //skip the current input
            cin.ignore(numeric_limits<int>::max(), '\n');
        } 
        catch (string& e) {
            cout << "Out of range number!\n";
            //reset the flag
            cin.clear();
            //skip the current input
            cin.ignore(numeric_limits<int>::max(), '\n');
        }

    }

}