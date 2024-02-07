#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;
	int sum = 0;
	int count = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;

		if (num == 1) {
			++count;
			sum += count;
		}

		else {
			count = 0;
		}
	}

	cout << sum;
}