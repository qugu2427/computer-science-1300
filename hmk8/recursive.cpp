#include <string>

std::string decimalToBinaryRecursive(int n){
    if(n == 0){ return "0"; }
    std::string out = "";
    out = std::to_string(n % 2) + out;
    n = n/2;
    return decimalToBinaryRecursive(n) + out;
}