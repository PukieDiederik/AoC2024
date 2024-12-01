#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
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
    std::unordered_map<int, int> a;
    std::unordered_map<int, int> b;
    while(std::getline(in, l))
    {
        int ia = std::atoi(l.c_str()), ib = std::atoi(l.c_str() + 8);
        std::unordered_map<int, int>::iterator ita = a.find(ia), itb = b.find(ib);

        // Insert or increase value
        if (ita == a.end())
            a.insert(std::pair(ia, 1));
        else
            ita->second++;

        if (itb == b.end())
            b.insert(std::pair(ib, 1));
        else
            itb->second++;
    }

    // Calculate result
    int result = 0;
    for (std::unordered_map<int, int>::iterator it = a.begin(); it != a.end(); ++it)
    {
        std::unordered_map<int, int>::iterator itb = b.find(it->first);
        if (itb != b.end()) // Add to result if the number is in both maps
            result += it->first * it->second * itb->second;
    }

    std::cout << "result: " << result << std::endl;
}