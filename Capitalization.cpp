#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {

    // user data
    string userName;
    char userChar;
    string capitalizedName;
    bool validName;

     do{
        validName = true;
        cout << "Enter your name: ";
        getline(cin, userName);

        for(int i=0; i<userName.length(); i++){
            if((isalpha(userName.at(i)) == false)  && (userName.at(i) != ' ')){
                validName = false;
                cout << userName.at(i);
            }
        }
        if(validName == false){
            cout << "Your name can only have alphabets and spaces. Enter again." << endl;
        }

    }while(validName == false);

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

    cout << capitalizedName;

    return 0;
}
                