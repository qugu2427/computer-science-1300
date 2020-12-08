#include <string>

std::string decimalToBinaryIterative(int n){
    if(n == 0){ return "0"; }
    std::string out = "";
    for(int i = 0;n > 0;i++){
        out = std::to_string(n % 2) + out;
        n = n/2;
    }
    return out;
}