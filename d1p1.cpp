#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

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

    // input parsing
    std::string l;
    std::vector<int> a;
    std::vector<int> b;
    while(std::getline(in, l))
    {
        a.push_back(std::atoi(l.c_str()));
        b.push_back(std::atoi(l.c_str() + 8));
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
    }

    // Calculate result
    int result = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        result += std::abs(a[i] - b[i]);
        std::cout << std::abs(a[i] - b[i]) << std::endl;
    }

    std::cout << "result: " << result << std::endl;
}