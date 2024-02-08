#include <iostream>
#include <vector>

using namespace std;

int n;
long long answer = 0;
vector <vector <int>> v;
vector <vector <long long>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    v.resize(n, vector <int>(n));
    dp.resize(n, vector <long long>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }

    dp[0][0] = v[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + v[i][j];
            }
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + v[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + v[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        answer = max(answer, dp[n - 1][i]);
    }

    cout << answer;

    return 0;
}