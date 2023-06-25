// N�� M (2)���� if���� ���ְ�, func(i + 1, k + 1) ��� func(i, k + 1)�� �ִ´�.

#include <iostream>

using namespace std;

int n, m;
int arr[10] = { 0, };
bool check[10] = { 0, };

void func(int num, int k);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	// 1���� Ž�� ����, 0�� ° ���̺��� Ž��
	func(1, 0);
}

void func(int num, int k) {
	// ��ǥ�� ������ ���ϴ� ������ �����ߴٸ�
	if (k == m) {
		// k = 1�� ���� k = 2�� ���� ��� �� ���
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = num; i <= n; i++) {
		// k��° ���̿��� ���ʴ�� ���� �־��
		arr[k] = i;
		// �湮�� ���� üũ ó��
		check[i] = 1;
		// k��° ������ ������ �ϳ� �� ū ������ �����ϹǷ�, i + 1�� �ְ�, 1��ŭ�� ���̸� �� ���� Ž��
		// for���� index ���� ����Լ��� ���ڷ� �Ѱ������ν� �̹� ã�� ������ �ٽ� ���� �ʵ��� ��
		func(i, k + 1);
		// ��� �� return�� �����鼭, false�� �ٽ� �ٲ��ֱ�
		check[i] = 0;
	}
}