// vector�� insert�� ������ ������.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;

	cin >> n;

	vector <int> arr(n);

	for (int i = 1; i <= n; i++) {
		cin >> tmp;

		arr.insert(arr.begin() + tmp, i);	// arr.begin() + tmp�� ���ο� ���Ұ� �߰��� ��ġ(index), i�� ������ ������ ��
	}

	// �Ųٷ� ���
	for (int i = n - 1; i >= 0; i--)
		cout << arr[i] << ' ';
}