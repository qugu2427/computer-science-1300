#include <iostream>
#include <string>

using namespace std;

void reverse(string str);

int main(){
    reverse("Hello world!");
}

void reverse(string str){
    for(int i = str.length() - 1;i >= 0;i--){
        cout << str[i];
    }
    cout << endl;
}