#include <iostream>
#include <iomanip>

using namespace std;

void stats(double arr[], int len) {
    double min, max, avg;
    min = arr[0];
    max = arr[0];
    double sum = 0;
    for(int i = 0;i < len;i++){
        if(min > arr[i]){
            min = arr[i];
        }
        if(max < arr[i]){
            max = arr[i];
        }
        sum += arr[i];
    }
    avg = sum / len;
    cout.precision(2);
    cout << "Min: " << fixed << min << endl;
    cout << "Max: " << fixed << max << endl;
    cout << "Avg: " << fixed << avg << endl;
}

int main() {
    double arr[] = {0,1,2,3,4,5,6,7,8,9};
    stats(arr, 10);
}