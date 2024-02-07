// �־��� n�� ������ 1���� 1000�����̹Ƿ�, �迭���� 1�϶��� ��츦 �߰��Ѵ�.

#include <iostream>

using namespace std;

int n;
long long arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	arr[1] = 1;
	arr[2] = 3;
	arr[3] = 5;

	for (int i = 4; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
	}

	cout << arr[n] % 10007;
}