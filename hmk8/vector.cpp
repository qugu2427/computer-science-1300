#include <iostream>
#include <vector>

int main() {
    bool quit = false;
    std::vector<int> nums;
    while(!quit){
        int in;
        std::cout << "Please enter a number:" << std::endl;
        std::cin >> in;
        if(in < 1 && in != -1){
            std::cout << "The number should be a positive integer or -1." << std::endl;
        } else if(in == -1){
            quit = true;
        } else if(nums.empty()){
            nums.push_back(in);
        } else if(in % 5 == 0 || in % 3 == 0){
            if(!nums.empty() && in % 5 == 0) {
                nums.erase(nums.begin());
            }
            if(!nums.empty() && in % 3 == 0) {
                nums.pop_back();
            } 
        } else {
            nums.push_back(in);
        }
    }
    if(nums.empty()){
        std::cout << "The vector is empty." << std::endl;
    } else {
        int min = nums[0];
        int max = nums[0];
        std::cout << "The elements in the vector are: ";
        for(size_t i = 0;i < nums.size();++i){
            if(nums[i] > max){
                max = nums[i];
            }
            if(nums[i] < min){
                min = nums[i];
            }
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Min = " << min << "\nMax = " << max << std::endl;
    }
    return 0;
}