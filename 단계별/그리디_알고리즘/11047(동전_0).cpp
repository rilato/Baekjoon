#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, num;
	int count = 0;
	vector <int> v;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	while (1) {
		// K�� 0�̸� ������ ������ ��� �� ���̹Ƿ� Ż��
		if (!K)
			break;

		// ������ ���� ���س���
		count += K / v.back();
		// ������ �������� K�� ����
		K %= v.back();
		// �� ���� ��Ҹ� ����
		v.pop_back();
	}

	cout << count;
}