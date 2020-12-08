#include <iostream>
#include <string>

using namespace std;

const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

int main() {
    string alphabet = ALPHABET;
    unsigned int height;
    cout << "Enter the height:" << endl;
    cin >> height;
    while(height > 0){
        if(height > alphabet.size()){
            alphabet += ALPHABET;
        }
        cout << alphabet.substr(0, height) << endl;
        alphabet = alphabet.substr(height, alphabet.size());
        height--;
    }
}
