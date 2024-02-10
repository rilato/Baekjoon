// 문제를 제대로 읽자. 범위가 1000000(백만)까지이다. 테스트케이스가 100000(십만)까지이다.
// 에라토스테네스의 체를 사용할 때 십만이 아닌 백만까지 돌린다.

#include <iostream>
#include <vector>

using namespace std;

int n;
vector <bool> prime(1000001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	prime[0] = true;
	prime[1] = true;

	for (int i = 2; i <= 1000000; i++) {
		for (int j = i + i; j <= 1000000; j += i) {
			prime[j] = true;
		}
	}

	while (1) {
		bool flag = true;

		cin >> n;

		if (n == 0) {
			break;
		}

		for (int i = 3; i <= n; i++) {
			if (!prime[i] && !prime[n - i]) {
				cout << n << " = " << i << " + " << n - i << '\n';
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}
