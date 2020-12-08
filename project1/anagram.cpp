#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int countWords;
string flipTwoChars(string str);
string anagram(string str);

int main(){
    cout << anagram("I have a inquiry for you: Do you estimate that the party in question will make physical contact with a specified surface, inanimate or otherwise, or have you theorised an alternative course of action, in which the opposite shall become truth. I, for one, would like to accentuate my support of the former notion. You, yourself, have, by means unknown to me, come to possess a human spouse, of the male variety, though it is within reason that I should assume said spouse, at the present stage, makes no attempt at performing the act of 'kissing', where one plants their lips upon the flesh of their lover counterpart in a show of affection. The auditory equivalent of a 'kiss' involves one pressing their lips together and having them protrude from the facial region, as they form the linguistic process most accurately represented with 'mwah'. My current train of thought would also have me conclude that the aforementioned male spouse of yours will most likely abandon your courtship, with the aim of eloping with another female love interest, with whom he'll show bountiful adoration for and an absence of regret when picturing himself having remained with you. He will, once all prior actions have been completed, skrrt, in which a crude, vocal mimicking of the sound produced by the shoes of basketball players, as they are forcefully slid across the wooden court itself, is made, as well as 'dab': the act of one bringing a single hand to their chest, and resting their face in the ridge created between the respective bicep and forearm, whilst the adjacent arm is extended away from the body until parallel with the previously defined one. He will perform this 'dab' in a manner resembling that of a male adult associated with the name Wiz Khalifa.");
}

string flipTwoChars(string str){
    if(str.length() <= 3){
        return str;
    }
    int flipPos = rand()%((str.length()-3)-1 + 1) + 1;
    char temp = str[flipPos];
    str[flipPos] = str[flipPos + 1];
    str[flipPos + 1] = temp;
    return str;
}

string anagram(string str){
    stringstream ss(str);
    vector<string> words;

    while(getline(ss, str, ' ')){
        words.push_back(str);
    }

    string anagramed = "";
    for(unsigned int i = 0;i < words.size();i++){
        words[i] = flipTwoChars(words[i]);
        anagramed += words[i] + " ";
    }

    return anagramed;
}