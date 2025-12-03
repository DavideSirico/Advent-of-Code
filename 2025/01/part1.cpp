#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


int part1(fstream &file);
int part2(fstream &file);
int main() {
    fstream cin("input.2.txt");
    cout << part2(cin) << endl;
    

    return 0;
}

int part2(fstream &file) {
    int start = 50;
    int res = 0;
    while(!file.eof()) {
        string line;
        file >> line;
        char rotation = line[0];
        int value = stoi(line.substr(1));
        cout << line << endl;
        if(rotation == 'L') {
            for(int i = 0; i < value; i++) {
                start = start - 1;
                start = (start % 100 + 100) % 100;
                cout << start << endl;
                if(start == 0) {
                    res++;
                }
            }
        } else if(rotation == 'R') {
            for(int i = 0; i < value; i++) {
                start = start + 1;
                start = (start % 100 + 100) % 100;
                
                cout << start << endl;

                if(start == 0) {
                    res++;
                }
            }
        }
    }
    return res;
}


int part1(fstream &file) {
    int start = 50;
    int res = 0;
    while(!file.eof()) {
        string line;
        file >> line;
        char rotation = line[0];
        int value = stoi(line.substr(1));

        if(rotation == 'L') {
            start = (start - value) % 100;
        } else if(rotation == 'R') {
            start = (start + value) % 100;
        }

        if (start == 0) {
            res++;
        }
    }
    return res;
}

