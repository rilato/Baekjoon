#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	int count = 0;
	vector <int> v;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		if (!(N % i)) {
			v.push_back(i);
			++count;
		}
	}

	if (count < K)
		cout << 0;
	else
		cout << v[K - 1];
}