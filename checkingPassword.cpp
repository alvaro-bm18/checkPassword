#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strongPasswordChecker(string password){
    const int MIN_SIZE = 8;
    const int MAX_SIZE = 20;
    int lower = 0, upper = 0, digits = 0, concecutive = 0;
    int minimumChanges = 0;
    int passwordSize = password.length();

    if(passwordSize > MAX_SIZE || passwordSize < MIN_SIZE) minimumChanges++;

    for(int c = 0; c < passwordSize; c++){

        digits += (isdigit(password[c])) ? 1 : 0;
        lower  += (islower(password[c])) ? 1 : 0;
        upper  += (isupper(password[c])) ? 1 : 0;

        if((c + 2) <= passwordSize){

            if(password[c] == password[c+1] && password[c+1] == password[c+2])
                concecutive++;
        }
    }

    //Insertion, deletion or replacement of any one character is considered one change.

    vector <string> needs;
    if(digits == 0){
        minimumChanges++;
        needs.push_back("digit");
    }
    if(lower  == 0){
        minimumChanges++;
        needs.push_back("lowercase letter");
    }
    if(upper  == 0){
        minimumChanges++;
        needs.push_back("uppercase letter");
    }

    int difference = 0;
    cout << password << endl;
    if(passwordSize < MIN_SIZE){
        // insert CHARACTERS
        difference = MIN_SIZE - passwordSize;
        cout << passwordSize << " characters total, need " << difference << " character, ";

        if(!needs.empty()){

           if(difference == needs.size()){
              for(string need : needs){
                cout << need << endl;
              }
           }else if( difference > needs.size()){
              for(string need : needs){
                cout << need << endl;
              }
              cout << (difference - needs.size()) << " any other characters" << endl;
           }else{
              // need.size() > difference
              cout << '\n' << " you need to remplace " << needs.size() - difference << " characters, " << endl;
              if(lower  == 0) cout << " You need a lowercase letter " << endl;
              else if( lower > 1 ) cout << " You could change a lowercase letter" << endl;

              if(upper  == 0) cout << " You need a uppercase letter " << endl;
              else if( upper > 1 ) cout << " You could change a uppercase letter" << endl;

              if(digits == 0) cout << " You need a digit " << endl;
              else if( digits > 1) cout << " You could change a digit" << endl;
           }
        }
    }
    else if (passwordSize >= MIN_SIZE && MAX_SIZE >= passwordSize){
        if(!needs.empty()){
            // remplacement CHARACTERS
            if(lower  == 0) cout << " You need to change a character for a lowercase letter " << endl;
            else if( lower > 1 ) cout << " You could change a lowercase letter" << endl;

            if(upper  == 0) cout << " You need to change a character for a uppercase letter " << endl;
            else if( upper > 1 ) cout << " You could change a uppercase letter" << endl;

            if(digits == 0) cout << " You need to change a character for a digit " << endl;
            else if( digits > 1) cout << " You could change a digit" << endl;
        }
    }else{
        cout << " You must cut " << passwordSize - MAX_SIZE << " characters" << endl;
        // remove CHARACTERS
        if(!needs.empty()){
           for( string n : needs ) cout << " You could change any digit for a " << n << endl;
        }
    }

    return minimumChanges;
}


int main(){
    string passwordToCheck = "holaWorld12";
    strongPasswordChecker(passwordToCheck);
    return 0;
}
