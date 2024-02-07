#include <iostream>
#include <vector>

using namespace std;

int N, num;
int cnt = 0;
vector <bool> prime(1001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	prime[0] = true;
	prime[1] = true;

	for (int i = 2; i <= 1000; i++) {
		for (int j = i + i; j <= 1000; j += i) {
			prime[j] = true;
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> num;

		if (!prime[num]) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
