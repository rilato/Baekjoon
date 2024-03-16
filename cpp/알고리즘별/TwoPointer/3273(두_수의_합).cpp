#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X, l, r;
int cnt = 0;
vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	cin >> X;

	sort(v.begin(), v.end());

	l = 0;
	r = v.size() - 1;

	// l == r인 경우, 탈출해야 한다. 같은 숫자를 두 번 더하는 꼴이기 때문.
	while (l < r) {
		if (v[l] + v[r] == X) {
			cnt++;
			l++;
		}
		else if (v[l] + v[r] > X) {
			r--;
		}
		else if (v[l] + v[r] < X) {
			l++;
		}
	}

	cout << cnt;

	return 0;
}
