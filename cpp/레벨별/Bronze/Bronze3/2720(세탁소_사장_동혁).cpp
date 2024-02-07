#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, Q, D, N, P;
    int change;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> change;

        Q = change / 25;
        change %= 25;

        D = change / 10;
        change %= 10;

        N = change / 5;
        change %= 5;

        P = change;

        cout << Q << " " << D << " " << N << " " << P << "\n";
    }
}