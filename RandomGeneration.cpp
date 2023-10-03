#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main (){

    srand(time(0));
    int upperbound;
    int lowerbound;

    // random number generation
    upperbound = (rand()% 101) + 100;
    do{
        lowerbound = (rand()% 101) + 100;
    }while( upperbound < lowerbound);

    cout << upperbound << endl;
    cout << lowerbound << endl;
    return 0;
}