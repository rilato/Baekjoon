// �ð� �ʰ��� �� Ǯ��
// for���� �����ϰ� ����ߴ�.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i, j;

	cin >> N >> M;

	vector <int> v(N);

	for (int k = 0; k < N; k++) {
		cin >> v[k];
	}

	for (int k = 0; k < M; k++) {
		int sum = 0;

		cin >> i >> j;

		for (int l = i - 1; l < j; l++) {
			sum += v[l];
		}

		cout << sum << '\n';
	}
}


// ���� Ǯ��
// ������� �Է°��� ���� �����س�����.
// ���� sum[j] - sum[i - 1]�� �Ѵ�.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i, j;
	int num;

	cin >> N >> M;

	vector <int> v(N + 1);
	v[0] = 0;

	for (int k = 1; k <= N; k++) {
		cin >> num;
		v[k] = v[k - 1] + num;
	}

	for (int k = 0; k < M; k++) {
		int sum = 0;

		cin >> i >> j;

		cout << v[j] - v[i - 1] << '\n';
	}
}