#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;
	int sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		sum += num;
	}

	cout << sum - N + 1;
}