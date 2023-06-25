// 문제가 무슨 말인지 이해가 잘 안됐다.
// 그래서 다른 사람의 풀이를 참고하였다.
// https://velog.io/@sw0000j/%EB%B0%B1%EC%A4%80C-1059-%EC%A2%8B%EC%9D%80-%EA%B5%AC%EA%B0%84

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int L;

	cin >> L;

	vector<int> v(L);

	bool issame = false;

	for (int i = 0; i < L; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int n;

	cin >> n;

	for (int i = 0; i < L; i++) {
		if (v[i] == n) {
			issame = true;
			break;
		}
	}

	if (issame) {
		cout << 0 << "\n";
	}

	else {
		int start = 0;
		int end = 0;

		for (int i = 0; i < L; i++) {
			if (v[i] > n) {
				start = v[i - 1];
				end = v[i];
				break;
			}
		}

		int ans = 0;

		for (int i = start + 1; i < end; i++) {
			for (int j = i + 1; j < end; j++) {
				// cout << i << " " << j << "\n";
				if (i <= n && n <= j) {
					ans++;
				}
			}
		}

		cout << ans << "\n";
	}
}