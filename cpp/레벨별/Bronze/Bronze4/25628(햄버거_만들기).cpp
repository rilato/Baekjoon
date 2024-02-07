#include <iostream>

using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	N /= 2;

	if (N <= M) {
		cout << N;
	}
	else {
		cout << M;
	}
}
