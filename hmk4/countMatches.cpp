#include <iostream>
#include <string>

using namespace std;

int main() {
    string searchString, subString;
    cout << "Enter the search string:" << endl;
    getline(cin, searchString);
    cout << "Enter the substring to be searched:" << endl;
    getline(cin, subString);
    int occurences = 0;
    int pos = searchString.find(subString);
    while(pos != string::npos){
        occurences++;
        searchString = searchString.substr(pos + 1, searchString.size());
        pos = searchString.find(subString);
    }
    cout << "Number of occurrences: " << occurences << endl;
}
