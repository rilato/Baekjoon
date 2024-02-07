// Ʋ�� Ǯ��

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int sum = 0;
	int cnt = 1;

	cin >> N;

	for (int i = 1; i < N; i++) {
		sum += i;

		for (int j = i + 1; j < N; j++) {
			if (sum >= N) {
				if (sum == N)
					cnt++;
				sum = 0;
				break;
			}
			else
				sum += j;
		}
	}

	cout << cnt;
}


// ���� Ǯ��

//l <= r, r <= n �ε��� loop�� ���� ������ �����մϴ�.

//1. ���� ���ӱ����� ���� n���� �۴ٸ� r�� �����ݴϴ�.
//2. �̻��� ���� sum == n�� ���� sum > n�� ��찡 �ֽ��ϴ�.sum == n�̶�� �ٷ� ans�� �����ݴϴ�.�ƴѰ��� ���� ������ l���� sum���� ���ѵ� l++���ݴϴ�.

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int sum = 0;
	int ans = 1;
	int l = 1;
	int r = 1;

	cin >> n;

	while (l <= r && r <= n) {
		if (sum < n)
			sum += r++;
		else {
			if (sum == n)
				ans++;
			sum -= l++;
		}
	}

	cout << ans;
}