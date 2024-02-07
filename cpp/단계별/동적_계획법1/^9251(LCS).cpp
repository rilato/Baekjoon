// https://rolypolytoy.tistory.com/43
// 아이패드 필기 참고

#include <iostream>
#include <algorithm>

using namespace std;

string S1, S2;
int len1, len2;
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S1 >> S2;

	len1 = S1.size();
	len2 = S2.size();

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			// 비교하는 문자의 위치가 서로 같은 경우
			// 왼쪽 대각선 값 + 1
			if (S1[i - 1] == S2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			// 비교하는 문자의 위치가 서로 다른 경우
			// max(왼쪽 값, 위쪽 값)
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[len1][len2];
}