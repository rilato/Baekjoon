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
		v[i] = v[i] + i + 2; // 첫 번째 부터 시작 (+1), 묘목은 심는데 1일 (+1)
	}

	sort(v.begin(), v.end());

	cout << v.back();
}