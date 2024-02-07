// 1, 2, 3, 4, ... , N���� ���� �ְ�,
// �� ������ ĥ�� �� �ִ� ������ �� �� �־�����.
// �� �ึ�� �� ���� �ִ� ���� �ƴϴ�!

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

    // N��° ���� ����� N-1��°���� ���� ���� ���� �ƴ�, �ٸ� �� ��, �ּ� ���� �� �ڽ��� ���� ���� ��
    for (int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
    }

    cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);

    return 0;
}