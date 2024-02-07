// 1, 2, 3, 4, ... , N까지 집이 있고,
// 각 집마다 칠할 수 있는 색상이 세 개 주어진다.
// 각 행마다 세 집이 있는 것이 아니다!

#include <iostream>
#include <vector>

using namespace std;

int N;
vector <vector <int>> v;
vector <vector <int>> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N, vector <int>(3));
    dp.resize(N, vector <int>(3));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }

    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    // N번째 집의 비용은 N-1번째에서 나와 같은 열이 아닌, 다른 열 중, 최소 값에 나 자신의 값을 더한 값
    for (int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
    }

    cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);

    return 0;
}