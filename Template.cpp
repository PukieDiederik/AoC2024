#include <iostream>
#include <fstream>

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

    std::cout << "result: " << "RESULT HERE" << std::endl;
}