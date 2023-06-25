// N과 M (2)에서 if문을 없애고, func(i + 1, k + 1) 대신 func(i, k + 1)를 넣는다.

#include <iostream>

using namespace std;

int n, m;
int arr[10] = { 0, };
bool check[10] = { 0, };

void func(int num, int k);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	// 1부터 탐색 시작, 0번 째 깊이부터 탐색
	func(1, 0);
}

void func(int num, int k) {
	// 목표인 깊이의 원하는 개수에 도달했다면
	if (k == m) {
		// k = 1인 곳과 k = 2인 곳에 담긴 값 출력
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = num; i <= n; i++) {
		// k번째 깊이에서 차례대로 숫자 넣어보기
		arr[k] = i;
		// 방문한 곳은 체크 처리
		check[i] = 1;
		// k번째 깊이의 값보다 하나 더 큰 값부터 시작하므로, i + 1을 넣고, 1만큼의 깊이를 더 들어가서 탐색
		// for문의 index 값을 재귀함수의 인자로 넘겨줌으로써 이미 찾은 조합은 다시 뽑지 않도록 함
		func(i, k + 1);
		// 출력 후 return을 만나면서, false로 다시 바꿔주기
		check[i] = 0;
	}
}