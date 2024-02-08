#include <iostream>
#include <vector>

using namespace std;

int N;
vector <vector <long long>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dp.resize(N + 1, vector <long long>(2));

    // dp[N자리수][0 또는 1]
    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[N][0] + dp[N][1];

    return 0;
}