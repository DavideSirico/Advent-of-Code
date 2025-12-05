#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int part1(string line) {
    int first_digit = 0;
    int best = 0;
    int current = 0;
    for (char c : line) {
        current = c-'0';
        // provo a creare un numero usando come prima cifra il massimo e come seconda cifra il current
        if((first_digit * 10) + current > best) {
            best = (first_digit * 10) + current;
        }
        if(current > first_digit) {
            first_digit = current;
        }

    }
    cout << best << endl;
    return best;
}

int digits_to_int(vector<int> digits) {
    int number = 0;
    for(int i = 11; i >= 0; i--) {
        number += digits[i]*pow(10,12-i);
    }
    return number;
}

int part2(string line) {
    // 12 numeri invece di 2
    vector<int> digits(12);
    int best = 0;
    int current = 0;
    int digit_counter = 0;
    for (char c : line) {
        current = c-'0';
        if(digits_to_int(digits) + current > best) {
            best = digits_to_int(digits) + current;
        }
        if(current > digits[digit_counter]) {
            digits[digit_counter] = current;
            digit_counter++;
        }
    }
    cout << best << endl;
    return best;
}
int main() {
    fstream cin("input.txt");

    vector<char> lines;

    string line;
    int res;
    while (getline(cin, line)) {
        // res+=part1(line);
        res+=part2(line);
    }

    cout << res;
    
    return 0;
}
