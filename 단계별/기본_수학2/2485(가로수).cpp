#include <iostream>
#include <vector>

using namespace std;

int N, temp;
int gcd = 1000000000;

void GCD(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector <int> v(N);
	vector <int> gap;

	for (int i = 0; i < N; i++) {
		cin >> v[i];

		if (i >= 1)
			gap.push_back(v[i] - temp);

		temp = v[i];
	}

	for (int i = 0; i < N - 2; i++) {
		GCD(gap[i], gap[i + 1]);
	}

	cout << (v.back() - v.front()) / gcd - v.size() + 1;
}

void GCD(int a, int b) {
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}

	if (a <= gcd)
		gcd = a;
}