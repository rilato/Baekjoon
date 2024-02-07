// 틀린 풀이
// 배열을 사용했더니 세그폴트 문제가 발생한다.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, A, B;
	int maxN = 0;
	int maxDP = 0;
	int arr[101] = { 0, };
	int dp[101] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A >> B;

		if (A > maxN)
			maxN = A;

		arr[A] = B;
	}

	for (int i = 1; i <= maxN; i++) {
		dp[i] = 1;

		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		maxDP = max(maxDP, dp[i]);
	}

	cout << N - maxDP;
}



// 틀린 풀이 2
// for문에서 배열의 길이를 정확하게 해줬더니
// 런타임 에러는 발생하지 않았으나, 틀렸습니다가 떴다.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, A, B;
	int maxDP = 0;
	int arr[101] = { 0, };
	int dp[101] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A >> B;

		arr[A] = B;
	}

	for (int i = 1; i <= 100; i++) {
		dp[i] = 1;

		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		maxDP = max(maxDP, dp[i]);
	}

	cout << N - maxDP;
}



// 맞은 풀이
// vector <pair> 를 이용한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, A, B;
	int maxDP = 0;
	int dp[101] = { 0, };
	vector <pair <int, int>> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A >> B;

		v.push_back({ A, B });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		dp[i] = 1;

		for (int j = 0; j <= i; j++) {
			if (v[i].second > v[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}

		maxDP = max(maxDP, dp[i]);
	}

	cout << N - maxDP;
}