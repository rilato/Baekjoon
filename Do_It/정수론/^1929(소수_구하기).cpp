// 소수가 아닌 수는 항상 sqrt(N)보다 작은 약수를 가짐
// sqrt(N) 이하의 수의 배수를 모두 제거하면 1부터 N까지의 소수를 구할 수 있음

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> M >> N;

	// 0번째 인덱스는 사용하지 않으므로, N + 1로 사이즈 고정
	vector <int> A(N + 1);

	// 인덱스를 자신의 수로 채우기
	for (int i = 2; i <= N; i++) {
		A[i] = i;
	}

	// 소수가 아닌 수는 항상 sqrt(N)보다 작은 약수를 가짐
	// sqrt(N) 이하의 수의 배수를 모두 제거하면 1부터 N까지의 소수를 구할 수 있음
	for (int i = 2; i * i <= N; i++) {
		if (A[i] == 0)
			continue;

		// 자신을 제외한 배수부터 시작하여, 모든 배수 제거
		for (int j = i + i; j <= N; j += i) {
			A[j] = 0;
		}
	}

	for (int i = M; i <= N; i++) {
		if (A[i] != 0)
			cout << A[i] << '\n';
	}

	return 0;
}