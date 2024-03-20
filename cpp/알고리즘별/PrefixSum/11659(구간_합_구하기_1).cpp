#include <iostream>
#include <vector>

using namespace std;

int N, M, start, finish;
vector <int> v;
vector <int> sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	v.resize(N + 1);
	sum.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];

		sum[i] = sum[i - 1] + v[i];
	}

	while (M--) {
		cin >> start >> finish;

		cout << sum[finish] - sum[start - 1] << '\n';
	}

	return 0;
}
