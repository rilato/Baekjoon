#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v;
vector <vector <int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N);
	dp.resize(N, vector <int>(3));

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	// 0 : �ȸ��� / 1 : ó������ ���� / 2 : �� �� ���� ����
	dp[0][0] = 0;
	dp[0][1] = v[0];
	dp[0][2] = 0;

	for (int i = 1; i < N; i++) {
		// �ȸ��Ŵٴ� ����, ������ �ȸ��̰ų�, �� �� ���̰ų�, �� �� ���� ������ �����
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		// ó������ ���Ŵٴ� ����, ������ �ȸ��� ��� + ���� ���� ���ô� �����
		dp[i][1] = dp[i - 1][0] + v[i];
		// �� �� ���� ���Ŵٴ� ����, ������ �� �� ���� ��� + ���� ���� ���ô� �����
		dp[i][2] = dp[i - 1][1] + v[i];
	}

	cout << max(dp[N - 1][0], max(dp[N - 1][1], dp[N - 1][2]));

	return 0;
}