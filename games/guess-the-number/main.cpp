#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int string_to_int(char const *s) {
    if (s == NULL | *s == '\0') {
        throw std::invalid_argument("Null or empty string");
    }

    bool negative = (s[0] == '-');
    if (*s == '+' || *s == '-') {
        ++s;
    }
    if ( *s == '\0' ) {
        throw std::invalid_argument("Sign character only");
    }

    int res = 0;
    while (*s) {
        if (*s < '0' || *s > '9') {
            throw std::invalid_argument("invalid string input");
        }
        res = res * 10 - (*s - '0');
        s++;
    }
    return negative ? res : -res;
}

int main() {
    srand(time(NULL)); // randomise seed
    int number = rand() % 100 + 1; // number between 1 and 100
    string input;
    int guess;
    cout << "Guess a number between 1 and 100." << endl;
    bool gameover = false;
    while (!gameover) {
        cout << "> ";
        cin >> input;
        try {
            guess = string_to_int(input.c_str());
            if (guess < 0 || guess > 100) {
                throw std::invalid_argument("Guess out of bounds");
            }
        } catch ( invalid_argument ) {
            cout << "Invalid Input! Please input a number between 1 and 100." << endl;
            continue;
        }

        if (guess < number) {
            cout << "Higher!" << endl;
        } else if (guess > number) {
            cout << "Lower!" << endl;
        } else {
            cout << "Congratulations! The number was: " << number << endl;
            gameover = true;
        }
    }
    return 0;
}

