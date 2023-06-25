#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;

    cin >> N;

    while (1) {
        if (N == 1) {
            cout << 1;
            break;
        }

        if (N % 2) {
            cout << 0;
            break;
        }

        N /= 2;
    }

    return 0;
}