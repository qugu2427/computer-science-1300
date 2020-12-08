#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c);
int numVowels(string str);

int main(){
    cout << numVowels("oiufpweb wiwebwbvwp ev") << endl;
}

bool isVowel(char c){
    c = tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}

int numVowels(string str){
    int count = 0;
    for(unsigned int i = 0;i < str.length();i++){
        if(isVowel(str[i])){
            count++;
        }
    }
    return count;
}