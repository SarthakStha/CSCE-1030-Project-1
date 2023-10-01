#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main (){

    // user data
    string userName;

    // user prompt variables
    srand(time(0));
    enum options {displayLeft = 1, displayRight = 2, guess = 3, change = 4, exit = 5};
    int userChoice;
    options choices;

    //random number guess range
    int upperbound;
    int lowerbound;
    int displayedLBound = -1;
    int displayedRBound = -1;

    //score system variable
    int userScore = 100;
    int pointGain = 5;
    int pointLoss = 5;
    int userGuess;

    // First codition to end program
    bool gameOver = false;

    //User name capitalization
    cout << "Enter your name: ";
    getline(cin, userName);
    // random number generation
    upperbound = (rand()% 101) + 100;
    do{
        lowerbound = (rand()% 101) + 100;
    }while( upperbound < lowerbound);
    
    
    do{

        //upperbound and lower bound display
        cout << displayedLBound << "     " << displayedRBound << endl;

        //user choice prompt
        cout << "1. Display Left Number" << endl;
        cout << "2. Display Right Number" << endl;
        cout << "3. Guess a number in between" << endl;
        cout << "4. Change Numbers" << endl;
        cout << "5. Exit" << endl;

        cin >> userChoice;

        choices = static_cast<options>(userChoice);

            switch(choices){
                case displayLeft:

                        // Right bound check
                        if(displayedRBound == -1){                   
                        
                            displayedLBound = lowerbound;
                            pointGain = 1;
                            pointLoss = 10;                           
                            cout << "Now, you will gain " << pointGain << "  points for guessing correctly and lose " << pointLoss << " for guessing incorrectly" << endl;
                        
                        } else{
                            cout << "You have already displayed the right boundary, you cannot display both." << endl;
                        };

                    break;
        
                case displayRight:

                        //Left bouond check
                        if(displayedLBound == -1){                   
                        
                            displayedRBound = upperbound;
                            pointGain = 1;
                            pointLoss = 10;                          
                            cout << "Now, you will gain " << pointGain << "  points for guessing correctly and lose " << pointLoss << " for guessing incorrectly" << endl;
                        
                        } else{
                            cout << "You have already displayed the left boundary, you cannot display both." << endl;
                        }

                    break;

                case guess:

                    //taking user guess
                    cout << "Enter your guess: ";
                    cin  >> userGuess;

                    // Range check
                    if ((userGuess>=lowerbound)&&(userGuess <= upperbound)){
                        userScore = userScore + pointGain; 
                        cout << "You guessed correctly. You gain " << pointGain << " points." <<endl;
                        cout << "Your remaining points = " << userScore << "." << endl;
                    } else{
                        userScore = userScore - pointLoss; 
                        cout << "You guessed incorrectly.You lose " << pointLoss << " points." << endl;
                        cout << "Your remaining points = " << userScore << "." << endl;
                    }

                    break;

                case change:

                        cout << "new range has been generated" << endl;
                        pointGain = 5;
                        pointLoss = 5;  

                        //generating a new range
                        upperbound = (rand()% 101) + 100;
                        do{
                            lowerbound = (rand()% 101) + 100;
                        }while( upperbound < lowerbound);

                        //refreshing the displayed range to their initial value
                        displayedLBound = -1;
                        displayedRBound = -1;

                    break;

                case exit:

                        gameOver = true;
                        cout << "Bye";

                    break;

                default:
                        
                        cout << "The choice you have selected is not valid try again";
                    
                    break;
    }
    }while( (gameOver != true) && (userScore >= 0));

        cout << "You are out of points." << endl;
        cout << "Bye";



    return 0;

}