#include <iostream>
#include <string>

using namespace std;

double temps[10];
string colors[5] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
int sequence[100];
char letters[52];

template<typename T>
void printArray(T arr[], int size) {   ;
    for(int i = 0;i < size;i++){
        cout << arr[i] << endl;
    }
}

int main() {
    // Populate temps
    fill_n(temps, 10, -459.67);
    // Populate sequence
    for(int i = 0;i < 100;i++){
        sequence[i] = i + 1;
    }
    printArray(temps, 10);
    cout << endl;
    printArray(colors, 5);
    cout << endl;
    printArray(sequence, 100);
    cout << endl;
    // Populate and print letters
    int i = 0;
    for(int j = 0;j < 26;j++){
        letters[i] = (char)(j+65);
        letters[i+1] = tolower((char)(j+65));
        cout << letters[i] << " " << letters[i+1] << endl;
        i+=2;
    }
}