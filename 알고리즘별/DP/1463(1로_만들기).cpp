#include <iostream>

using namespace std;

int X;
int dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X;

    dp[1] = 0;

    for (int i = 2; i <= X; i++) {
        if (i % 2 == 0 && i % 3 == 0) {
            dp[i] = min(min(dp[i / 2], dp[i / 3]), dp[i - 1]) + 1;
        }
        else if (i % 2 == 0) {
            dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
        }
        else if (i % 3 == 0) {
            dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
        }
        else {
            dp[i] = dp[i - 1] + 1;
        }
    }

    cout << dp[X];

    return 0;
}