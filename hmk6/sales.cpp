#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>

using namespace std;

string clean(string str){
    string cleaned = "";
    for(int i = 0;i < str.length();i++){
        if(str[i] != '\r' && str[i] != ' '){
            cleaned += str[i];
        }
    }
    return cleaned;
}

int readSales(string fileName, string names[], int sales[][12], int size) {
    int returnSize = 0;
    ifstream readFile(fileName);
    if(!readFile.is_open()){ return -1; }
    for(int i = 0;i < size;i++){
        string nameLine;
        getline(readFile, nameLine);
        nameLine = clean(nameLine);
        if(nameLine == ""){ return returnSize; }
        names[i] = nameLine;
        string salesLine;
        getline(readFile, salesLine);
        salesLine = clean(salesLine) + ",";

        // Split sales line & calculate avg
        string saleStr = "";
        double sum = 0;
        int k = 0;
        //cout << salesLine << endl;
        for(int j = 0;j < salesLine.length();j++){
            if(salesLine[j] == ','){
                int sale = stod( saleStr );
                //cout << sale << endl;
                sum += sale;
                saleStr = "";
                sales[i][k] = sale;
                k++;
                continue;
            }
            saleStr += salesLine[j];
        }
        cout.precision(1);
        cout << names[i] << ": " << fixed << sum/12 << endl;
        returnSize++;
    }
    readFile.close();
    return returnSize;
}

int main() {
    const int SIZE = 3;
    string names[SIZE];
    int sales[SIZE][12];

    readSales("sales.txt", names, sales, SIZE);
}
