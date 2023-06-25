// vector의 type으로 <구조체>를 넣을 수 있다.
// 그 값으로 int, string 등을 넣을 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b);

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	string input;

	cin >> N;

	// 벡터의 사이즈를 확실하게 정해줘야 벡터의 범위를 벗어나는 에러가 발생하지 않는다.
	vector<string> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i] << '\n';
	}
}

bool compare(string a, string b) {
	// 길이가 다른 경우 짧은 것이 먼저 온다.
	if (a.size() != b.size())
		return a.size() < b.size();
	else {
		int asize = a.size();
		int bsize = b.size();
		int asum = 0;
		int bsum = 0;

		// 숫자인 경우, 그 합을 더한다.
		for (int i = 0; i < asize; i++) {
			if (0 <= a[i] - '0' && a[i] - '0' <= 9)
				asum += a[i] - '0';
		}

		for (int i = 0; i < bsize; i++) {
			if (0 <= b[i] - '0' && b[i] - '0' <= 9)
				bsum += b[i] - '0';
		}

		// 숫자의 합이 다른 경우, 숫자의 합이 작은 것이 먼저 오도록 한다.
		if (asum != bsum)
			return asum < bsum;
		// 숫자의 합이 같은 경우, 알파벳 순으로 오게 한다.
		else
			return a < b;
	}
}