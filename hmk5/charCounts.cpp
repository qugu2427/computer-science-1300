#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cout << "Enter a word:" << endl;
    cin >> word;
    int counts[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i = 0;i < word.length();i++){
        counts[((int)word[i]) - 97]++;
    }
    for(int i = 0;i < 26;i++){
        int count = counts[i];
        if(count > 0){
            cout << (char)(i + 97) << ": " << counts[i] << endl;
        }
    }
}
