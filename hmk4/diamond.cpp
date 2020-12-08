#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int length;
    cout << "Enter the length:" << endl;
    cin >> length;

    // up
    int spaces = length;
    for(int i = 1;i < length * 2;i += 2){
        cout << spaces << " ";
        string str = "";
        for(int j = 0;j < i;j++){
            str += "*";
        }
        for(int j = 0;j < spaces;j++){
            str = " " + str;
        }
        spaces--;
        cout << str << endl;
    }

    // down
    spaces = 2;
    for(int i = (length * 2) - 1;i > 0;i -= 2){
        cout << spaces << " ";
        if(i == (length * 2) - 1){
            continue;
        }
        string str = "";
        for(int j = 0;j < i;j++){
            str += "*";
        }
        for(int j = 0;j < spaces;j++){
            str = " " + str;
        }
        spaces++;
        cout << str << endl;
    }
}