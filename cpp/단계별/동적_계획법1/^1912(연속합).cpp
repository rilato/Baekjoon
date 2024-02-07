// https://guiyum.tistory.com/16
// https://snnchallenge.tistory.com/67
// �����е忡 �ʱ� ����

// ���� �ܰ� ������ �հ�, ������ ���� �������� �����Ѵ�.

#include <iostream>
#include <algorithm>

using namespace std;

int N[100000];
int dp[100000];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> N[i];

	dp[0] = N[0];

	int result = dp[0];

	for (int i = 1; i < n; i++) {
		// dp ���� ���� �հ� ���� �� �� ū ���� �����Ͽ� �ִ´�.
		dp[i] = max(dp[i - 1] + N[i], N[i]);

		// result���� ��������� ���� �� �� ���� ū ��� ���� �����Ѵ�.
		result = max(result, dp[i]);
	}

	cout << result << endl;
}