// Ʋ�� Ǯ��
// ���� Ž���� ���� �ʾ�, �ð� �ʰ��� �߻��ߴ�.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num;
	vector <int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;

		v.push_back(num);
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;

		for (int j = 0; j < v.size(); j++) {
			if (v[j] == num) {
				cout << 1 << " ";
				break;
			}
			if (j == v.size() - 1 && v[j] != num)
				cout << 0 << " ";
		}
	}
}



// ���� Ǯ��
// ����� �Լ��� binary_search()�� �̿��Ͽ� ���� Ž���� �����Ͽ���.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, num;
	vector <int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;

		cout << binary_search(v.begin(), v.end(), num) << " ";
	}
}