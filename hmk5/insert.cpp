#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
void printArray(T arr[], int size) {
    for(int i = 0;i < size;i++){
        cout << arr[i] << ",";
    }
    cout << endl;
}

int insert(int arr[], int numElems, int size, int value) {
    if(numElems == size){
        return numElems;
    }
    for(int i = numElems - 1;i >= 0;i--){
        if(arr[i] > value){
            arr[i+1] = arr[i];
        } 
        else {
            arr[i+1] = value;
            return numElems + 1;
        }
    }
    arr[0] = value;
    return numElems + 1;
}

int main() {
    int arr[10] = {1,1,3,4,5,5,5,6};
    int numElems = 8;
    int size = 10;
    int value = 2;
    numElems = insert(arr, numElems, size, value);
    printArray(arr, numElems);
}