// 재귀를 바탕으로 하는 백트래킹 방법을 숙지한다
// vector를 for문으로 출력할 때, auto를 이용한 출력을 확인한다.

#include<iostream>
#include<vector>

using namespace std;

int N, M;
bool visited[9] = { 0, };
vector <int> v;

void backTracking();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	backTracking();
}

void backTracking() {
	if (v.size() == M) {
		for (auto& k : v)
			cout << k << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			backTracking();
			visited[i] = false;
			v.pop_back();
		}
	}
}

// 다른 풀이

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
	// 0번 째 깊이부터 탐색
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

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
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
}