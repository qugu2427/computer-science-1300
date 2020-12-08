#include <iostream>

using namespace std;

void computeHireScore(double agility, double strength,  double speed){
    cout << "Hire score: " << (1.8 * agility + 2.16 * strength + 3.24 * speed) << endl;
}

int main() {
    bool loop = true;
    while(loop){
        int animalNum;
        double agility, strength, speed;
        cout << "Select a numerical option:\n=== menu ===\n1. Fox\n2. Bunny\n3. Sloth\n4. Quit" << endl;
        cin >> animalNum;
        switch (animalNum)
        {
            case 1:
                cout << "Enter agility:" << endl;
                cin >> agility;
                cout << "Enter strength:" << endl;
                cin >> strength;
                computeHireScore(agility, strength, 0);
                break;
            case 2:
                cout << "Enter agility:" << endl;
                cin >> agility;
                cout << "Enter speed:" << endl;
                cin >> speed;
                computeHireScore(agility, 0, speed);
                break;
            case 3:
                cout << "Enter strength:" << endl;
                cin >> strength;
                cout << "Enter speed:" << endl;
                cin >> speed;
                computeHireScore(0, strength, speed);
                break;
            case 4:
                cout << "Good bye!" << endl;
                loop = false;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
        cin.clear();
        cin.ignore(10000, '\n');
    }
}