#include <iostream>
#include <vector>

std::vector<int> shuffle(std::vector<int> v1, std::vector<int> v2){
    std::vector<int> rv;
    bool v1Longer = true;
    if(v2.size() > v1.size()){ v1Longer = false; }
    for(int i = 0;i < v1.size() || i < v2.size();i++){
        if(v1Longer){
            if(i < v1.size()){
                rv.push_back(v1[i]);
            }
            if(i < v2.size()){
                rv.push_back(v2[i]);
            }
        } else {
            if(i < v2.size()){
                rv.push_back(v2[i]);
            }
            if(i < v1.size()){
                rv.push_back(v1[i]);
            }
        }
    }
    return rv;
}

int main(){
    using namespace std;
    vector<int> v1{1,3,5,9};
    vector<int> v2{2,4,6,8,10};
    vector<int> v3 = shuffle(v1,v2);
    for (int i=0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
}