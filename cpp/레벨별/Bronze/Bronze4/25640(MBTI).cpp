#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string mbti, s;
	int N;
	int cnt = 0;

	cin >> mbti >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;

		if (mbti == s)
			cnt++;
	}

	cout << cnt;

	return 0;
}
