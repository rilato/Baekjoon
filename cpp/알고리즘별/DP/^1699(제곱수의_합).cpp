#include <iostream>
#include <vector>

using namespace std;

int N, answer;
vector <int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dp.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        dp[i] = i;

        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[N];

    return 0;
}
