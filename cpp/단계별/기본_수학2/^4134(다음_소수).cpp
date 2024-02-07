#include <iostream>

using namespace std;

long long T, N;

bool isPrime(long long n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    while (T--) {
        cin >> N;

        while (1) {
            if (isPrime(N)) {
                break;
            }

            N++;
        }

        cout << N << endl;
    }

    return 0;
}

bool isPrime(long long n) {
    if (n == 0 || n == 1) {
        return false;
    }

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
