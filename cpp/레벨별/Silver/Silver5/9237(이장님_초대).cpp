#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < n; i++) {
		v[i] = v[i] + i + 2; // ù ��° ���� ���� (+1), ������ �ɴµ� 1�� (+1)
	}

	sort(v.begin(), v.end());

	cout << v.back();
}