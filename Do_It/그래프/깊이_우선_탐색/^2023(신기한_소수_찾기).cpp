// visited 배열을 사용하지 않는 DFS 문제
// pruning을 이용한 백트래킹 기법과 유사

#include <iostream>

using namespace std;

int N;

void DFS(int number, int jarisu);
bool isPrime(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 첫 자리가 2, 3, 5, 7로 시작해야 첫 번째 자리가 소수라는 조건을 만족
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	return 0;
}

void DFS(int number, int jarisu) {
	// 리턴 (출력) 조건 설정
	if (jarisu == N) {
		if (isPrime(number)) {
			cout << number << '\n';
		}

		return;
	}

	//for (int i = 0; i < 10; i++) {
	//	// 짝수인 경우, 무조건 소수가 아니므로 패스
	//	if (i % 2 == 0) {
	//		continue;
	//	}

	//	// 현재 탐색중인 number에 10을 곱하고 i를 더한 수 (자리수 + 1인 수)가 소수였다면, 탐색 진행
	//	if (isPrime(number * 10 + i)) {
	//		DFS(number * 10 + i, jarisu + 1);
	//	}
	//}

	for (int i = 1; i < 10; i += 2) {
		if (isPrime(number * 10 + i)) {
			DFS(number * 10 + i, jarisu + 1);
		}
	}
}

bool isPrime(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return false;
	}

	return true;
}