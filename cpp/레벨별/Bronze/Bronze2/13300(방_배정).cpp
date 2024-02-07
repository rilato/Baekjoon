#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, r, c;
	int result = 0;
	int arr[2][6] = { 0, };

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> r >> c;

		arr[r][c - 1]++;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			result += ceil((double)arr[i][j] / K);
		}
	}

	cout << result;
}