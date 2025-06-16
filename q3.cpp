#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int target[5];
int tries = 0;
bool found = false;

bool isMatch(int guess[]) {
    for (int i = 0; i < 5; i++) {
        if (guess[i] != target[i])
            return false;
    }
    return true;
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i];
    cout << endl;
}

void solve(int guess[], int pos) {
    if (pos == 5) {
        tries++;
        if (isMatch(guess)) {
            found = true;
            cout << "Correct key found: ";
            print(guess, 5);
        }
        return;
    }

    for (int d = 0; d <= 9; d++) {
        if (found) return;
        guess[pos] = d;
        if (pos < 3) {
            cout << "Level " << pos << ": ";
            print(guess, pos + 1);
        }
        solve(guess, pos + 1);
    }
}

int main() {
    srand(time(0));
    for (int i = 0; i < 5; i++)
        target[i] = rand() % 10;

    int guess[5] = {0};
    solve(guess, 0);

    cout << "Total attempts: " << tries << endl;

    cout << "Actual key was: ";
    print(target, 5);

    return 0;
}
