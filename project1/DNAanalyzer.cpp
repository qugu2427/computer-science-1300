#include <iostream>
#include <string>

using namespace std;

double calcSimScore(string s1, string s2);
double findBestSimScore(string genome, string sequence);
void findMatchedGenome(string g1, string g2, string g3, string sequence);

int main(){
    bool loop = true;
    while(loop){
        cout << "Select a numerical option:\n=== menu ===\n1. Find similarity score\n2. Find the best similarity score\n3. Analyze the genome sequences\n4. Quit" << endl;
        int option;
        cin >> option;
        switch(option){
            case 1:
                {
                    string s1, s2;
                    cout << "Enter sequence 1:" << endl;
                    cin >> s1;
                    cout << "Enter sequence 2:" << endl;
                    cin >> s2;
                    cout << "Similarity score: " << calcSimScore(s1, s2) << endl;
                    break;
                }
            case 2:
                {
                    string genome, sequence;
                    cout << "Enter genome:" << endl;
                    cin >> genome;
                    cout << "Enter sequence:" << endl;
                    cin >> sequence;
                    cout << "Best similarity score: " << findBestSimScore(genome, sequence) << endl;
                    break;
                }
            case 3:
                {
                    string g1, g2, g3, s;
                    cout << "Enter genome 1:" << endl;
                    cin >> g1;
                    cout << "Enter genome 2:" << endl;
                    cin >> g2;
                    cout << "Enter genome 3:" << endl;
                    cin >> g3;
                    cout << "Enter sequence:" << endl;
                    cin >> s;
                    findMatchedGenome(g1, g2, g3, s);
                    break;
                }
            case 4:
                cout << "Good bye!" << endl;
                loop = false;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    }
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

void findMatchedGenome(string g1, string g2, string g3, string sequence){
    if(g1.length() == 0 || g2.length() == 0 || g3.length() == 0 || sequence.length() == 0){
        cout << "Genomes or sequence is empty." << endl;
        return;
    }
    if( !(g1.length() == g2.length() && g1.length() == g3.length()) ){
        cout << "Lengths of genomes are different." << endl;
        return;
    }
    double g1Score = findBestSimScore(g1, sequence);
    double g2Score = findBestSimScore(g2, sequence);
    double g3Score = findBestSimScore(g3, sequence);
    double bestScore = g1Score;
    if(g2Score > bestScore){
        bestScore = g2Score;
    }
    if(g3Score > bestScore){
        bestScore = g3Score;
    }

    if(g1Score == bestScore){
        cout << "Genome 1 is the best match." << endl;
    }
    if(g2Score == bestScore){
        cout << "Genome 2 is the best match." << endl;
    }
    if(g3Score == bestScore){
        cout << "Genome 3 is the best match." << endl;
    }
}