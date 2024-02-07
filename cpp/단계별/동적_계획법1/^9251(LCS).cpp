// https://rolypolytoy.tistory.com/43
// �����е� �ʱ� ����

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
			// ���ϴ� ������ ��ġ�� ���� ���� ���
			// ���� �밢�� �� + 1
			if (S1[i - 1] == S2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			// ���ϴ� ������ ��ġ�� ���� �ٸ� ���
			// max(���� ��, ���� ��)
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[len1][len2];
}