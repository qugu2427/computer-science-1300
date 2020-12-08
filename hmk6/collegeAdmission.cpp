#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>

using namespace std;

string clean(string str){
    string cleaned = "";
    for(int i = 0;i < str.length();i++){
        if(str[i] != '\r'){
            cleaned += str[i];
        }
    }
    return cleaned;
}

bool isOutlier(int interest, double normGPA, double normSAT, double score){
    return (interest == 0 || (normGPA-2) > normSAT) && score >= 5;
}

bool isImprovement(int sem1, int sem2, int sem3, int sem4, double score){
    return sem1 < sem2 && sem2 < sem3 && sem3 < sem4 && score >= 5;
}

int main() {
    string fileName;
    cout << "Enter the file name:" << endl;
    cin >> fileName;
    ifstream readFile(fileName);
    if(!readFile.is_open()){ cout << "Could not open file." << endl; return 0; }
    cout << "\nResults:" << endl;
    string line;
    getline(readFile, line); // Pass first line
    while(getline(readFile, line)){
        line = clean(line) + ",";
        
        // Set value
        string seg = "";
        string segs[9];
        int j = 0;
        for(int i = 0;i < line.length();i++){
            if(line[i] == ','){
                segs[j] = seg;
                j++;
                seg = "";
                continue;
            }
            seg += line[i];
        }
        string student = segs[0];
        double sat = stod(segs[1]) / (double)160;
        double gpa = stod(segs[2]) * (double)2;
        int interest = stod(segs[3]);
        int hsQuality = stod(segs[4]);
        int sem1 = stod(segs[5]);
        int sem2 = stod(segs[6]);
        int sem3 = stod(segs[7]);
        int sem4 = stod(segs[8]);

        /* DEBUGGIN
        cout << "sat: " << sat << endl;
        cout << "gpa: " << gpa << endl;
        cout << "interest: " << interest << endl;
        cout << "hsQuality: " << hsQuality << endl;
        cout << "sem1: " << sem1 << endl;
        cout << "sem2: " << sem2 << endl;
        cout << "sem3: " << sem3 << endl;
        cout << "sem4: " << sem4 << endl;
        */

        // Calculate score
        double score = 0.4*gpa + 0.3*sat + 0.2*hsQuality + 0.1*interest;

        // Print
        if(score >= 6){
            cout << student << "," << score << ",score" << endl;
        } else if(isOutlier(interest,gpa,sat,score)){
            cout << student << "," << score << ",outlier" << endl;
        } else if(isImprovement(sem1, sem2, sem3, sem4, score)){
            cout << student << "," << score << ",grade improvement" << endl;
        } else {
            cout << student << "," << score << endl;
        }

    }
    readFile.close();
}
