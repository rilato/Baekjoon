#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		vector <int> v;
		long long sum = 0;

		cin >> N;

		if (N == -1)
			break;

		for (int i = 1; i < N; i++) {
			if (N % i == 0) {
				v.push_back(i);
				sum += i;
			}
		}

		if (sum == N) {
			cout << N << " = ";

			for (int i = 0; i < v.size() - 1; i++) {
				cout << v[i] << " + ";
			}

			cout << v[v.size() - 1] << '\n';
		}
		else {
			cout << N << " is NOT perfect.\n";
		}
	}

	return 0;
}