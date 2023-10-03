#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main (){

    int userChoice;
    int displayedLBound = -1;
    int displayedRBound = -1;

        //upperbound and lower bound display
        cout << displayedLBound << "     " << displayedRBound << endl;
        //user choice prompt
        cout << "1. Display Left Number" << endl;
        cout << "2. Display Right Number" << endl;
        cout << "3. Guess a number in between" << endl;
        cout << "4. Change Numbers" << endl;
        cout << "5. Exit" << endl;

        cin >> userChoice;

        return 0;

}