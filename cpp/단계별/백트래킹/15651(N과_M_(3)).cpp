// 사실상 N과 M(1)에서 자기 자신을 다시 뽑을 수 있도록하는 규칙만 추가된 문제이다.
// if(!visited[i])를 통해, 만약 1이라는 숫자가 뽑혀있다면 다음 원소로 1을 뽑지 않도록 했던 조건문을 제거해주면 15651번의 해답을 얻을 수 있다.

#include <iostream>

using namespace std;

int n, m;
int arr[10] = { 0, };
bool check[10] = { 0, };

void func(int k);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	// 1부터 탐색 시작, 0번 째 깊이부터 탐색
	func(0);
}

void func(int k) {
	// 목표인 깊이의 원하는 개수에 도달했다면
	if (k == m) {
		// k = 1인 곳과 k = 2인 곳에 담긴 값 출력
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	// N과 M (1) 과 달리, if의 조건을 없앰으로써 1부터 빠짐없이 모두 탐색하도록 한다.
	for (int i = 1; i <= n; i++) {
		// k번째 깊이에서 차례대로 숫자 넣어보기
		arr[k] = i;
		// 방문한 곳은 체크 처리
		check[i] = 1;
		// 1만큼의 깊이를 더 들어가서 탐색
		func(k + 1);
		// 출력 후 return을 만나면서, false로 다시 바꿔주기
		check[i] = 0;
	}
}