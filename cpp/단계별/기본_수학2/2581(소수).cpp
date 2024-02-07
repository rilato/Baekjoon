#include <iostream>

using namespace std;

int primeNumber(int num);

int main() {
    int start, end, num;
    int sum = 0;
    int min = 10000;

    cin >> start >> end;

    for (int i = start; i <= end; i++) {
        if (primeNumber(i) != 0) {
            sum += primeNumber(i);
            if (primeNumber(i) <= min)
                min = primeNumber(i);
        }
    }

    if (sum == 0)
        cout << -1;
    else
        cout << sum << '\n' << min;
}

int primeNumber(int num) {
    if (num == 1)
        return 0;

    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            return 0;
    }

    return num;
}