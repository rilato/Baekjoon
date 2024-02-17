#include <iostream>
#include <vector>

using namespace std;

int N, answer;
vector <int> v;
vector <int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N);
    dp.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    dp[0] = v[0];
    answer = v[0];

    for (int i = 1; i < N; i++) {
        // 지금까지 합 + 이번 숫자 < 이번 숫자라면
        if (dp[i - 1] + v[i] < v[i]) {
            // 이번 숫자부터 다시 세는게 맞다
            dp[i] = v[i];
        }
        // 지금까지 합 + 이번 숫자 >= 이번 숫자라면
        else {
            // 지금까지의 합을 계속 이어나간다
            dp[i] = dp[i - 1] + v[i];
        }

        answer = max(answer, dp[i]);
    }

    cout << answer;

    return 0;
}