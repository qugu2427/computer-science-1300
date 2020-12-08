#include <iostream>
#include <iomanip>

using namespace std;

int maxSum(int arr[][10], int rows) {
    int maxSum = 0;
    for(int i = 0;i < rows;i++){
        int len = sizeof(arr[i])/sizeof(arr[i][0]);
        int max = arr[i][0];
        for(int j = 0;j < len;j++){
            if(arr[i][j] > max){
                max = arr[i][j];
            }
        }
        maxSum += max;
    }
    return maxSum;
}

int main() {
    int arr[2][10] = {
        {1, 2, 3, 4, 5, 10, 9, 8, 7, 6},
        {5, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
    };
    cout << "returned value: " <<  maxSum(arr, 2);
}
