#include <iostream>

using namespace std;

bool primeNumber(int num);

int main() {
    int input, num;
    int count = 0;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        if (primeNumber(num))
            ++count;
    }

    cout << count << '\n';
}

bool primeNumber(int num) {
    if (num == 1)
        return false;

    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}