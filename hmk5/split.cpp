#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template<typename T>
void printArray(T arr[], int size) {
    for(int i = 0;i < size;i++){
        cout << arr[i] << ",";
    }
    cout << endl;
}

int split(string str, char delim, string arr[], int len){

    // How can a string be divided into 0 pieces?
    if(str.length() == 0){
        return 0; 
    }

    int pieces = 1;
    for(int i = 0;i < str.length();i++){
        if(str[i] == delim){
            pieces++;
            if(pieces > len){ return -1; }
            continue;
        }
        arr[pieces - 1] += str[i];
    }
    return pieces;
}



int main() {
    string words[10];
    int len = split("hwef whoffhew0fwefhweffwef w fwe fwef fwef", ' ', words, 10); 
    printArray(words, len);
}
