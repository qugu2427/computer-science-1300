#include<iostream>
#include <iomanip>

using namespace std;

int main(){
    float hoursWorked, payRate, payCheck;
    cout << "Enter the number of hours worked" << endl;
    cin >> hoursWorked;
    cout << "Enter an hourly pay rate" << endl;
    cin >> payRate;
    if(hoursWorked < 0 || payRate < 0){
        cout << "Invalid input" << endl;
        return 0;
    }
    payCheck = hoursWorked * payRate;
    if(hoursWorked > 40.0){
        payCheck += (hoursWorked - 40) * (0.5 * payRate);
    }
    cout << "Paycheck: " << fixed << setprecision(2) << payCheck << endl;
}