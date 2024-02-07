#include <iostream>

using namespace std;

int T, N;
int dp[12];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 12; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    while (T--) {
        cin >> N;

        cout << dp[N] << '\n';
    }

    return 0;
}