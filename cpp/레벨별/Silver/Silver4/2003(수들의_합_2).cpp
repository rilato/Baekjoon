#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int count = 0;

	cin >> N >> M;

	vector <long long> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < N; i++) {
		long long sum = v[i];

		if (sum == M) {
			++count;
			continue;
		}

		for (int j = i + 1; j < N; j++) {
			sum += v[j];

			if (sum == M) {
				++count;
				break;
			}

			if (sum > M) {
				break;
			}
		}
	}

	cout << count;
}