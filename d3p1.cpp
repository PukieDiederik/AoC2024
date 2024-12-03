#include <iostream>
#include <fstream>
#include <regex>
#include <string>

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

    std::string l;
    std::regex regexpr = std::regex("(mul\\(\\d{1,3},\\d{1,3}\\))");

    int result = 0;
    while (std::getline(in, l)){
        std::sregex_iterator s = std::sregex_iterator(l.begin(), l.end(), regexpr);
        for(std::sregex_iterator s = std::sregex_iterator(l.begin(), l.end(), regexpr);
            s != std::sregex_iterator();
            ++s){
            std::string mulLine = std::smatch(*s).str();

            int a = std::atoi(mulLine.c_str() + 4), b = std::atoi(mulLine.c_str() + mulLine.find(',') + 1);

            result += a * b;
        }
    }

    std::cout << "result: " << result << std::endl;
}