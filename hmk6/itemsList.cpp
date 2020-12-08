#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fileName;
    double mostExpensivePrice;
    string mostExpensive;
    double leastExpensivePrice;
    string leastExpensive;
    int lines = 0;

    cout << "Enter the file name:" << endl;
    cin >> fileName;

    ifstream readFile(fileName);
    if(readFile.is_open()){

        int lines = 0;
        string line;
        string item;
        double price;
        bool firstLine = true;


        while(getline(readFile, line)){
            int commaIndex = line.find(",");
            if(commaIndex == string::npos){ continue; }
            item = line.substr(0, commaIndex);
            price = stod( line.substr(commaIndex + 1, line.length()) );
            if(firstLine){
                leastExpensive = item;
                leastExpensivePrice = price;
                mostExpensive = item;
                mostExpensivePrice = price;
                firstLine = false;
            }
            else if(price > mostExpensivePrice){
                mostExpensive = item;
                mostExpensivePrice = price;
            }
            else if(price < leastExpensivePrice){
                leastExpensive = item;
                leastExpensivePrice = price;
            }
            lines++;
        }

        cout << "The number of lines: " << lines << endl; 
        cout << "The most expensive product: " << mostExpensive << endl; 
        cout << "The least expensive product: " << leastExpensive << endl; 
    } else {
        cout << "Could not open file." << endl;
    }
    readFile.close();
}