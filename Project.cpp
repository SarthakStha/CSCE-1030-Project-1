#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main (){

    // username data & valid check variables
    string userName;
    char userChar;
    string capitalizedName;
    bool validName;

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

    // Display student information
    cout << "+----------------------------------------------------+" << endl;
    cout << "| Computer Science and Engineering                   |" << endl;
    cout << "| CSCE 1030 - Computer Science I                     |" << endl;
    cout << "| Milan Chaulagain mc1623 MilanChaulagain@my.unt.edu |" << endl;
    cout << "| Prasuna Khadka pk0777 prasunakhadka@my.unt.edu     |" << endl;
    cout << "| Tarang Shiwakoti ts1366 TarangShiwakoti@my.unt.edu |" << endl;
    cout << "| Sarthak Shrestha ss3926 sarthakshrestha@my.unt.edu |" << endl;
    cout << "+----------------------------------------------------+" << endl;

    // Name vaild check

     do{
        validName = true;
        cout << "Enter your name: ";
        getline(cin, userName);

        for(int i=0; i<userName.length(); i++){
            if((isalpha(userName.at(i)) == false)  && (userName.at(i) != ' ')){
                validName = false;
            }
        }
        if(validName == false){
            cout << "Your name can only have alphabets and spaces. Enter again." << endl;
        }

    }while(validName == false);

    //User name capitalization

    for(int i= 0; i< userName.size(); i++){
        userChar = userName.at(i);
        if (i == 0){
            userChar = toupper(userName.at(i));
            capitalizedName += userChar;
        } else{

            if(userName.at(i-1) == ' '){
                userChar = toupper(userName.at(i));
                capitalizedName += userChar;
            } else{

                capitalizedName += userChar;

            }

        }

    };

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
                       // conndtion to end program
                        gameOver = true;

                    break;

                default:
                        
                        cout << "The choice you have selected is not valid try again";
                    
                    break;
            }
    }while( (gameOver != true) && (userScore >= 0));

        // condition to end program check
        if (gameOver != true){
        cout << "You are out of points." << endl;
        }else{
            cout << "Your final point balance is = " << userScore << endl;
        }
        cout << "Bye " << capitalizedName << " !!!" << endl;

    return 0;
}