// ��ǻ� N�� M(1)���� �ڱ� �ڽ��� �ٽ� ���� �� �ֵ����ϴ� ��Ģ�� �߰��� �����̴�.
// if(!visited[i])�� ����, ���� 1�̶�� ���ڰ� �����ִٸ� ���� ���ҷ� 1�� ���� �ʵ��� �ߴ� ���ǹ��� �������ָ� 15651���� �ش��� ���� �� �ִ�.

#include <iostream>

using namespace std;

int n, m;
int arr[10] = { 0, };
bool check[10] = { 0, };

void func(int k);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	// 1���� Ž�� ����, 0�� ° ���̺��� Ž��
	func(0);
}

void func(int k) {
	// ��ǥ�� ������ ���ϴ� ������ �����ߴٸ�
	if (k == m) {
		// k = 1�� ���� k = 2�� ���� ��� �� ���
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	// N�� M (1) �� �޸�, if�� ������ �������ν� 1���� �������� ��� Ž���ϵ��� �Ѵ�.
	for (int i = 1; i <= n; i++) {
		// k��° ���̿��� ���ʴ�� ���� �־��
		arr[k] = i;
		// �湮�� ���� üũ ó��
		check[i] = 1;
		// 1��ŭ�� ���̸� �� ���� Ž��
		func(k + 1);
		// ��� �� return�� �����鼭, false�� �ٽ� �ٲ��ֱ�
		check[i] = 0;
	}
}