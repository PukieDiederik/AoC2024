#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool isValid(std::vector<int>& nums, bool canRemove) {
    // Assume there are always at least 2 numbers
    if (nums[0] - nums[1] > 0){ // Descending
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] - nums[i + 1] <= 0 || // If it is not descending or 0
                nums[i] - nums[i + 1] > 3){ // If the gap is too big
                if (canRemove){
                    std::vector<int> newNumsA = nums;
                    std::vector<int> newNumsB = nums;
                    std::vector<int> newNumsC;

                    newNumsA.erase(newNumsA.begin() + i);
                    newNumsB.erase(newNumsB.begin() + i + 1);
                    if (i == 1){ // Seperate condition in case I got ascending/descending wrong on first one
                        newNumsC = nums;
                        newNumsC.erase(newNumsC.begin());
                    }

                    return (isValid(newNumsA, false) ||
                            isValid(newNumsB, false) ||
                            (i == 1 && isValid(newNumsC, false)));
                }
                else
                    return false;
            }
        }
    }
    else { // Ascending
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i + 1] - nums[i] <= 0 || // If it is not descending or 0
                nums[i + 1] - nums[i] > 3){ // If the gap is too big
                if (canRemove){
                    std::vector<int> newNumsA = nums;
                    std::vector<int> newNumsB = nums;
                    std::vector<int> newNumsC;
                    newNumsA.erase(newNumsA.begin() + i);
                    newNumsB.erase(newNumsB.begin() + i + 1);

                    if (i == 1){ // Seperate condition in case I got ascending/descending wrong on first one
                        newNumsC = nums;
                        newNumsC.erase(newNumsC.begin());
                    }

                    return (isValid(newNumsA, false) ||
                            isValid(newNumsB, false) ||
                            (i == 1 && isValid(newNumsC, false)));
                }
                else
                    return false;
            }
        }
    }
    return true;
}

int main(int argc, char**argv){
    if (argc != 2){ // We should always get an input file
        std::cerr << "Expected input file" << std::endl;
        return 1;
    }

    std::ifstream in = std::ifstream(argv[1]);
    if (!in.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    int result = 0;

    std::string l;
    while(std::getline(in, l)){
        // parse input
        std::vector<int> nums;
        for (std::string::size_type i = 0; i < l.size(); i = l.find(' ', i + 1)){
            nums.push_back(std::atoi(l.c_str() + i));
        }
        if (isValid(nums, true))
            ++result;
    }

    std::cout << "result: " << result << std::endl;
}