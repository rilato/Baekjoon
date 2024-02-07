// https://kdongree.tistory.com/75
#include <iostream>

using namespace std;

int T, N;
int dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            dp[j] += i;
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        dp[i] += dp[i - 1];
    }

    for (int j = 0; j < T; j++) {
        cin >> N;

        cout << dp[N] << '\n';
    }

    return 0;
}