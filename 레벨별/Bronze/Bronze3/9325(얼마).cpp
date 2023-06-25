#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, s, n, q, p;
    long long sum = 0;

    cin >> T;

    for (int k = 0; k < T; k++) {
        cin >> s >> n;

        for (int i = 0; i < n; i++) {
            cin >> q >> p;
            sum += p * q;
        }

        cout << sum + s << '\n';

        sum = 0;
    }

    return 0;
}