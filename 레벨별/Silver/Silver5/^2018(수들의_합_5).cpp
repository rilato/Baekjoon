// 틀린 풀이

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int sum = 0;
	int cnt = 1;

	cin >> N;

	for (int i = 1; i < N; i++) {
		sum += i;

		for (int j = i + 1; j < N; j++) {
			if (sum >= N) {
				if (sum == N)
					cnt++;
				sum = 0;
				break;
			}
			else
				sum += j;
		}
	}

	cout << cnt;
}


// 맞은 풀이

//l <= r, r <= n 인동안 loop를 돌며 다음을 수행합니다.

//1. 만약 연속구간의 합이 n보다 작다면 r을 더해줍니다.
//2. 이상일 때는 sum == n인 경우아 sum > n인 경우가 있습니다.sum == n이라면 바로 ans를 더해줍니다.아닌경우는 가장 왼쪽의 l값을 sum에서 제한뒤 l++해줍니다.

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int sum = 0;
	int ans = 1;
	int l = 1;
	int r = 1;

	cin >> n;

	while (l <= r && r <= n) {
		if (sum < n)
			sum += r++;
		else {
			if (sum == n)
				ans++;
			sum -= l++;
		}
	}

	cout << ans;
}