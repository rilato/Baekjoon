// 시간 초과가 난 풀이

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T, N, M, a, b;
int cnt = 0;
int arr[1001][1001];

int BFS(int v);
void reset();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--) {
		// T를 돌 때마다 minimum은 최대치로 매번 바꿔줘야 한다!
		// 무지성으로 전역변수에 쓰면 안됨!
		int minimum = 10001;

		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> a >> b;

			arr[a][b] = 1;
			arr[b][a] = 1;
		}

		for (int i = 1; i <= N; i++) {
			minimum = min(minimum, BFS(i));
		}

		cout << minimum << '\n';

		reset();
	}
}

int BFS(int v) {
	queue <int> q;
	bool visited[1001] = { 0, };

	q.push(v);
	visited[v] = true;
	int cnt = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (arr[v][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
				cnt++;
			}
		}
	}

	return cnt;
}

void reset() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = 0;
		}
	}
}


// 맞은 풀이
// https://melonicedlatte.com/algorithm/2018/08/31/120730.html
// 최소 신장 트리의 개념을 이해하고 이를 적용한다.

#include <iostream>  

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;

	cin >> T;

	while (T--) {
		int N, M;

		cin >> N >> M;

		for (int m_idx = 0; m_idx < M; m_idx++) {
			int a, b;
			cin >> a >> b;
		}

		cout << N - 1 << "\n";
	}

	return 0;
}