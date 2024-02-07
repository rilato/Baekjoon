#include <iostream>
#include <vector>

using namespace std;

int N;
long long sum = 0;
vector <vector <long long>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp.resize(101, vector <long long>(10));

    // DP 배열 초기화
    // DP[1][0] : 한 자리 수에서 맨 마지막 수가 0으로 끝난 경우
    dp[1][0] = 0;
    // DP[1][i] : 한 자리 수에서 맨 마지막 수가 i로 끝난 경우
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 100; i++) {
        dp[i][0] = dp[i - 1][1] % 1000000000;
        dp[i][9] = dp[i - 1][8] % 1000000000;

        for (int j = 1; j < 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    cin >> N;

    for (int i = 0; i < 10; i++) {
        sum += dp[N][i] % 1000000000;
    }

    cout << sum % 1000000000;

    return 0;
}