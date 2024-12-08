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

    for(int x = 0; x < ws[0].length(); ++x){
        for(int y = 0; y < ws.size(); ++y){
            if (ws[y][x] == 'X'){
                // Forward
                if (x < ws[0].length() - 3 && ws[y][x + 1] == 'M' && ws[y][x + 2] == 'A' && ws[y][x + 3] == 'S')
                    ++result;
                // Backward
                if (x > 2 && ws[y][x - 1] == 'M' && ws[y][x - 2] == 'A' && ws[y][x - 3] == 'S')
                    ++result;

                // Up
                if (y > 2 && ws[y - 1][x] == 'M' && ws[y - 2][x] == 'A' && ws[y - 3][x] == 'S')
                    ++result;
                // Down
                if (y < ws.size() - 3 && ws[y + 1][x] == 'M' && ws[y + 2][x] == 'A' && ws[y + 3][x] == 'S')
                    ++result;

                // DownRight
                if (y < ws.size() - 3 && x < ws[0].length() - 3 && ws[y + 1][x + 1] == 'M' && ws[y + 2][x + 2] == 'A' && ws[y + 3][x + 3] == 'S')
                    ++result;
                // DownLeft
                if (y < ws.size() - 3 && x > 2 && ws[y + 1][x - 1] == 'M' && ws[y + 2][x - 2] == 'A' && ws[y + 3][x - 3] == 'S')
                    ++result;
                // UpRight
                if (y > 2 && x < ws[0].length() - 3 && ws[y - 1][x + 1] == 'M' && ws[y - 2][x + 2] == 'A' && ws[y - 3][x + 3] == 'S')
                    ++result;
                // UpLeft
                if (y > 2 && x > 2 && ws[y - 1][x - 1] == 'M' && ws[y - 2][x - 2] == 'A' && ws[y - 3][x - 3] == 'S')
                    ++result;
            }
        }
    }

    std::cout << "result: " << result << std::endl;
}