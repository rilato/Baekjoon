#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	int answer = 0;

	cin >> N >> K;

	vector <int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if (A[i] > K)
			continue;

		answer += K / A[i];
		K %= A[i];
	}

	cout << answer;

	return 0;
}