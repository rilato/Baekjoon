#include <iostream>

using namespace std;

int T, N;
long long dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 1000001; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
    }

    while (T--) {
        cin >> N;

        cout << dp[N] % 1000000009 << '\n';
    }

    return 0;
}