#include <iostream>

using namespace std;

bool isVowel(char c);

int main(){
    cout << isVowel('a') << endl;
    cout << isVowel('f') << endl;
}

bool isVowel(char c){
    c = tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}