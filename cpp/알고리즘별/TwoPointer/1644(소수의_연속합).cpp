// right == primeNum.size()로 설정해주어야, out of bounds 에러가 발생하지 않는다.

// 틀린 풀이
#include <iostream>
#include <vector>

using namespace std;

int N;
long long sum = 0;
int cnt = 0;
vector <bool> isPrime;
vector <int> primeNum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	isPrime.resize(N + 1);

	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) {
			continue;
		}

		primeNum.push_back(i);

    // 맞은 풀이와 다른 부분
		if (N == i) {
			cnt++;
		}

		for (int j = i + i; j <= N; j += i) {
			isPrime[j] = true;
		}
	}

	int left = 0;
	int right = 0;

	while (1) {
    // 맞은 풀이와 다른 부분
		if (right == primeNum.size() - 1 && sum < N) {
			break;
		}

		if (sum == N) {
			cnt++;
			sum -= primeNum[left];
			left++;
		}
		else if (sum < N) {
			sum += primeNum[right];
			right++;
		}
		else if (sum > N) {
			sum -= primeNum[left];
			left++;
		}
	}

	cout << cnt;

	return 0;
}


// 맞은 풀이
#include <iostream>
#include <vector>

using namespace std;

int N;
long long sum = 0;
int cnt = 0;
vector <bool> isPrime;
vector <int> primeNum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	isPrime.resize(N + 1);

	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) {
			continue;
		}

		primeNum.push_back(i);

		for (int j = i + i; j <= N; j += i) {
			isPrime[j] = true;
		}
	}

	int left = 0;
	int right = 0;

	while (1) {
		if (right == primeNum.size() && sum < N) {
			break;
		}

		if (sum == N) {
			cnt++;
			sum -= primeNum[left];
			left++;
		}
		else if (sum < N) {
			sum += primeNum[right];
			right++;
		}
		else if (sum > N) {
			sum -= primeNum[left];
			left++;
		}
	}

	cout << cnt;

	return 0;
}
