#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;

    cout << "Guess a number between 1 and 100: ";

    int userGuess;
    while (true) {
        cin >> userGuess;
        if (userGuess == secretNumber) {
            cout << "Congratulations! You guessed the correct number!" << endl;
            break;
        } else if (userGuess > secretNumber) {
            cout << "Too high! Try a lower number. ";
        } else {
            cout << "Too low! Try a higher number. ";
        }
        cout << "Guess again: ";
    }

    return 0;
}
