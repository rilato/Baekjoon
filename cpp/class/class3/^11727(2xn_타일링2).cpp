// 주어진 n의 범위가 1부터 1000까지이므로, 배열에서 1일때의 경우를 추가한다.

#include <iostream>

using namespace std;

int n;
long long arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	arr[1] = 1;
	arr[2] = 3;
	arr[3] = 5;

	for (int i = 4; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
	}

	cout << arr[n] % 10007;
}