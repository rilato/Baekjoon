// N�� 1000�̹Ƿ�, bool �迭�� ����� 1001�� �������� �Ѵ�!!

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool arr[1001] = { 0, };
	int N, K;
	int cnt = 0;

	cin >> N >> K;

	for (int i = 2; i <= N; i++) {
		// j�� ���ϴ� ��, ����� �ϴ� ���� true�� �ٲ㳪����.
		for (int j = 1; i * j <= N; j++) {
			if (arr[i * j] == true)
				continue;

			arr[i * j] = true;
			++cnt;

			if (cnt == K) {
				cout << i * j;
				return 0;
			}
		}
	}
}