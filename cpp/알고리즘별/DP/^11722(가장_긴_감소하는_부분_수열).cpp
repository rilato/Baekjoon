// 가장 긴 증가하는 부분 수열 문제와 매우 유사하다

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

    for (int i = 0; i < N; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (v[i] < v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        answer = max(answer, dp[i]);
    }

    cout << answer;

    return 0;
}
