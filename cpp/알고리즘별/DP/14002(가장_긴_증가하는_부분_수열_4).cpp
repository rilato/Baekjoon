// 11053과 유사한 문제

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

    for (int i = 0; i < N; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        if (dp[i] > answer) {
            // 정답 갱신
            answer = dp[i];

            // 현재 dp 값
            int cnt = dp[i];

            // ans배열 clear한 후 새로 값 넣기
            ans.clear();

            for (int j = i; j >= 0; j--) {
                if (dp[j] == cnt) {
                    ans.push_back(v[j]);
                    cnt--;
                }
            }
        }
    }

    cout << answer << '\n';

    for (int i = answer - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}