#include<iostream>
#include <iomanip>

using namespace std;

int main(){
    double p1, p2, p3;
    cout << "Enter practicum 1 score:" << endl;
    cin >> p1;
    cout << "Enter practicum 2 score:" << endl;
    cin >> p2;
    cout << "Enter practicum 3 score:" << endl;
    cin >> p3;
    double avg = (p1 + p2 + p3) / 3.0;
    cout << "Practicum average: " << fixed << setprecision(2) << avg << endl;
    if(avg >= 67.0){
        cout << "You have a passing practicum average." << endl;
    }
    else{
        cout << "You can retake practicums during the final." << endl;
    }
}