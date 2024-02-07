#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	for (int i = 1; i <= T; i++) {
		int N;
		int max = 0;

		cin >> N;

		vector <int> v(N);

		for (int j = 0; j < N; j++) {
			cin >> v[j];
		}

		sort(v.begin(), v.end());

		for (int j = 0; j < N - 1; j++) {
			int temp = v[j + 1] - v[j];

			if (max < temp)
				max = temp;
		}

		cout << "Class " << i << '\n' << "Max " << v.back() << ", Min " << v.front() << ", Largest gap " << max << '\n';
	}
}