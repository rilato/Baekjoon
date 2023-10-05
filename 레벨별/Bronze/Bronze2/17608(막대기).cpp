#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int max = 0;
	int cnt = 1;
	bool flag = false;

	cin >> N;

	vector <int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = N - 1; i >= 1; i--) {
		if (!flag) {
			if (v[i] < v[i - 1]) {
				cnt++;
			}
			else {
				flag = true;
				max = v[i];
			}
		}
		else {
			if (v[i] > max) {
				max = v[i];
				cnt++;
			}
			if (i == 1) {
				if (v[i - 1] > max) {
					cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}
