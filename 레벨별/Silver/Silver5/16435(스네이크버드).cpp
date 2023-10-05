#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;

	cin >> N >> L;

	vector <int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		if (v[i] <= L) {
			L++;
		}
		else {
			break;
		}
	}

	cout << L;

	return 0;
}
