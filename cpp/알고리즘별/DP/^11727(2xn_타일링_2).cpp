#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v(1001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v[1] = 1;
	v[2] = 3;

	for (int i = 3; i <= N; i++) {
		// 1. i - 1��°���� �ϼ��� �Ϳ� 1 * 2 ���ϴ� ���
		// 2. i - 2��°���� �ϼ��� �Ϳ� 2 * 1 �� �� �Ǵ� 2 * 2 �� �� ���ϴ� ���
		// (�����, 1 * 2 �� ���� ���� ���̽��� ���Եȴ�. i - 1��° ������ 1 * 2�̰�, i��° ������ 1 * 2�� ���� �� ����̱� ����)
		v[i] = (v[i - 1] + v[i - 2] * 2) % 10007;
	}

	cout << v[N] % 10007;

	return 0;
}