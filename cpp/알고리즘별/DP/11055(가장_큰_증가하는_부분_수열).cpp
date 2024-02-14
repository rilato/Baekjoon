#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int answer = 0;
vector <int> v;
vector <int> dp;
vector <int> ans;

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

    // 1. 증가하는 부분 수열을 구한다.
    // 2. 그 중, 합이 가장 큰 것을 찾는다.

    for (int i = 0; i < N; i++) {
        dp[i] = v[i];

        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                // dp에 저장된 값과 현재 값을 더해서 dp[i]를 갱신한다.
                dp[i] = max(dp[i], dp[j] + v[i]);
            }
        }

        answer = max(dp[i], answer);
    }

    cout << answer;

    return 0;
}