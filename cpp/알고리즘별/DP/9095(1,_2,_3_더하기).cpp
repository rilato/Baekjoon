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


// 3 :
// 2를 만들 수 있는 경우의 수 + 마지막에 1 더하기 : dp[2][1] ~ dp[2][3]
// 1을 만들 수 있는 경우의 수 + 마지막에 2 더하기 : dp[1][1] ~ dp[1][3]
// 0을 만들 수 있는 경우의 수 + 마지막에 3 더하기 : dp[0][1] ~ dp[0][3]

#include <iostream>
#include <vector>

using namespace std;

int T, num;
vector <vector <int>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp.resize(11, vector <int>(4));

    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 0;
    dp[3][1] = 2;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i <= 10; i++) {
        dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    cin >> T;

    while (T--) {
        cin >> num;

        cout << dp[num][1] + dp[num][2] + dp[num][3] << '\n';
    }

    return 0;
}