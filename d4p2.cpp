#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

    std::string line;
    std::vector<std::string> ws;
    while (std::getline(in, line))
        ws.push_back(line);

    int result = 0;

    for(int x = 1; x < ws[0].length() - 1; ++x){
        for(int y = 1; y < ws.size() - 1; ++y){
            if (ws[y][x] == 'A'){
                if (((ws[y - 1][x - 1] == 'M' && ws[y + 1][x + 1] == 'S') ||
                     (ws[y - 1][x - 1] == 'S' && ws[y + 1][x + 1] == 'M')) &&
                    ((ws[y - 1][x + 1] == 'M' && ws[y + 1][x - 1] == 'S') ||
                     (ws[y - 1][x + 1] == 'S' && ws[y + 1][x - 1] == 'M')))
                    ++result;
            }
        }
    }

    std::cout << "result: " << result << std::endl;
}