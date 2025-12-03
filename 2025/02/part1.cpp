#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


unsigned long long part1(fstream &file);
int part2(fstream &file);
int main() {
    fstream cin("input.1.txt");
    cout << part1(cin) << endl;
    

    return 0;
}


bool isInvalid1(string num) {
    int length = num.length();
    string digits_to_check = "";
    for(int i = 0; i < length/2; i++) {
        digits_to_check += num[i];
    }
    // cout << digits_to_check << " " << number_of_digits_to_check;
    // se la stringa è composta solo da queste cifre ripetute
    // creo la stringa "corretta"
    string correct = digits_to_check+digits_to_check;
    if(correct == num) {
        return true;
    }

    return false;
}

bool isInvalid2(string num) {
    int length = num.length();
    
    for(int number_of_digits = 1; number_of_digits <= (length/2); number_of_digits++) {
        string digits_to_check = "";
        for(int i = 0; i < number_of_digits; i++) {
            digits_to_check += num[i];
        }

        string correct = "";
        
        for(int i = 1; i <= (length/number_of_digits); i++) {
            correct += digits_to_check;
        }
        // cout << number_of_digits << " " << digits_to_check << " "  << correct << endl;
        if(correct == num) {
            return true;
        }
    }

    return false;
}

unsigned long long part1(fstream &file) {
    unsigned long long res = 0;
    char delimitator = ',';
    string line;
    while(getline(file, line, delimitator)) {
        unsigned long long start;
        unsigned long long end;
        long half = line.find('-');
        string number1 = line.substr(0,half);
        string number2 = line.substr(half+1,line.length()-half);
        // cout << number1 << "-" << number2 << endl;
        start = stoll(number1);
        end = stoll(number2);
        for(unsigned long long i = start; i <= end; i++) {
            string num = to_string(i);
            // cout << num << endl;
            if(isInvalid2(num)) {
                // cout << i << endl;
                res = res+i;
            }
        }
    }
    return res;
}