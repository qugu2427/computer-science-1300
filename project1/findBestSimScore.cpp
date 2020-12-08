#include <iostream>
#include <string>

using namespace std;

double calcSimScore(string s1, string s2);
double findBestSimScore(string genome, string sequence);

int main(){
    cout << findBestSimScore("ATACGC", "ACT") << endl;
    cout << findBestSimScore("AG", "AG") << endl;
}

double calcSimScore(string s1, string s2){
    if(s1.length() != s2.length() || s1.length() == 0){
        return 0;
    }
    int matchCount = 0;
    for(int i = 0;i < s1.length();i++){
        if( s1[i] != s2[i]  ){
            matchCount++;
        }
    }
    return (s1.length() - (double)matchCount) / s1.length();
}
 
double findBestSimScore(string genome, string sequence){
    int subStrLen = sequence.length();
    double bestScore = 0;
    for(int i = 0;i + subStrLen <= genome.length();i++){
        string subStr = genome.substr(i, subStrLen);
        double score = calcSimScore(subStr, sequence);
        if(score > bestScore){
            bestScore = score;
        }
    }
    return bestScore;
}