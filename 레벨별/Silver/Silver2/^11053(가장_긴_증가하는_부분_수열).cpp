#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int answer = 0;

    cin >> N;

    vector <int> v(N);
    vector <int> dp(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N; i++) {
        dp[i] = 1;

        for (int j = i; j >= 0; j--) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        answer = max(dp[i], answer);
    }

    cout << answer;

    return 0;
}