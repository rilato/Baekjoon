#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;

	cin >> n >> m;

	vector <int> v(n + 1);

	v[0] = 1;

	for (int i = 1; i <= n; i++) {
		int num;

		cin >> num;

		v[i] = v[i - 1] + num;
	}

	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;

		cout << v[b] - v[a - 1] << '\n';
	}

	return 0;
}