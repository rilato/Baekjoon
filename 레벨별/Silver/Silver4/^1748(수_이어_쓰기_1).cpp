// �ð� �ʰ��� �� Ǯ��
// 1���� �����ؾ��ϹǷ� else ans += 9�� �� �ٿ��� �Ѵ�!!

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long ans = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i < 10)
			ans += 1;
		else if (i < 100)
			ans += 2;
		else if (i < 1000)
			ans += 3;
		else if (i < 10000)
			ans += 4;
		else if (i < 100000)
			ans += 5;
		else if (i < 1000000)
			ans += 6;
		else if (i < 10000000)
			ans += 7;
		else if (i < 100000000)
			ans += 8;
		else
			ans += 9;
	}

	cout << ans;
}


// ���� Ǯ��

// N - 1 + 1 : 1���� N������ �� ��, 1�� �ڸ� ���� ���� �ִ� ���� ����
// N - 10 + 1 : 1���� N������ �� ��, 10�� �ڸ� ���� ���� �ִ� ���� ����
// N - 100 + 1 : 1���� N������ �� ��, 100�� �ڸ� ���� ���� �ִ� ���� ����

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int cnt = 0;

	cin >> N;

	if (N < 10) {
		cout << N;
		return 0;
	}

	for (int i = 1; i <= N; i *= 10) {
		cnt += N - i + 1;
	}

	cout << cnt;
}