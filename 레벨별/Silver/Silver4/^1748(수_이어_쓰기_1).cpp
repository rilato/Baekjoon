// 시간 초과가 난 풀이
// 1억을 포함해야하므로 else ans += 9를 꼭 붙여야 한다!!

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long long ans = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		if (i < 10)
			ans += 1;
		else if (i < 100)
			ans += 2;
		else if (i < 1000)
			ans += 3;
		else if (i < 10000)
			ans += 4;
		else if (i < 100000)
			ans += 5;
		else if (i < 1000000)
			ans += 6;
		else if (i < 10000000)
			ans += 7;
		else if (i < 100000000)
			ans += 8;
		else
			ans += 9;
	}

	cout << ans;
}


// 맞은 풀이

// N - 1 + 1 : 1부터 N까지의 수 중, 1의 자리 수를 갖고 있는 수의 개수
// N - 10 + 1 : 1부터 N까지의 수 중, 10의 자리 수를 갖고 있는 수의 개수
// N - 100 + 1 : 1부터 N까지의 수 중, 100의 자리 수를 갖고 있는 수의 개수

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int cnt = 0;

	cin >> N;

	if (N < 10) {
		cout << N;
		return 0;
	}

	for (int i = 1; i <= N; i *= 10) {
		cnt += N - i + 1;
	}

	cout << cnt;
}