// N이 1000이므로, bool 배열의 사이즈를 1001로 만들어줘야 한다!!

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool arr[1001] = { 0, };
	int N, K;
	int cnt = 0;

	cin >> N >> K;

	for (int i = 2; i <= N; i++) {
		// j는 곱하는 수, 지우려 하는 수를 true로 바꿔나간다.
		for (int j = 1; i * j <= N; j++) {
			if (arr[i * j] == true)
				continue;

			arr[i * j] = true;
			++cnt;

			if (cnt == K) {
				cout << i * j;
				return 0;
			}
		}
	}
}