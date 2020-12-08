#include <iostream>

using namespace std;

void collatz(int n);

int main() {
    int n;
    cout << "Enter a positive number:" << endl;
    cin >> n;
    collatz(n);
}

void collatz(int n){
    cout << n << endl;
    if(n % 2 == 0){
        collatz(n/2);
    }
    else if(n != 1){
        collatz(3*n+1);
    }
}