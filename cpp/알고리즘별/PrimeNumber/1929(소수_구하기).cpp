#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <bool> prime(1000001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	prime[0] = true;
	prime[1] = true;

	for (int i = 2; i <= 1000000; i++) {
		if (!prime[i]) {
			for (int j = i + i; j <= 1000000; j += i) {
				prime[j] = true;
			}
		}
	}

	cin >> N >> M;

	for (int i = N; i <= M; i++) {
		if (!prime[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}
