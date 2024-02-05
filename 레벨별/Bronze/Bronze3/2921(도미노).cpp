#include <iostream>

using namespace std;

int N;
int sum = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			sum += i + j;
		}
	}

	cout << sum;

	return 0;
}
