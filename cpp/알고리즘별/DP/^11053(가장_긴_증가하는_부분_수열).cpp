#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int answer = 0;
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
        // dp값 1로 초기화 (현재 길이 1)
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            // 기준 값이 현재 살펴보는 값보다 크다면 갱신
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        // 정답을 최대값으로 갱신
        answer = max(dp[i], answer);
    }

    cout << answer;

    return 0;
}