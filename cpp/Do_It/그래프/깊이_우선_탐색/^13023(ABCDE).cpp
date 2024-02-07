// 특정한 친구로부터 연속된 5명의 친구가 있는 그래프가 있는지 찾는 문제이다.
// 따라서 방문했던 노드들에 대해 다시 visited[v] = false;로 되돌려

#include <iostream>
#include <vector>

using namespace std;

int N, M, a, b;
bool arrive = false;
vector <vector <int>> A;
vector <bool> visited;

void DFS(int v, int cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	A.resize(N);
	visited = vector <bool>(N, false);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		A[a].push_back(b);
		A[b].push_back(a);
	}

	// 친구는 무조건 0부터 시작. N - 1이 마지막 친구.
	// 0부터 N - 1까지 돌면서 5명의 친구가 연속해서 이어지는 애가 있는지 확인해야 함.
	for (int i = 0; i < N; i++) {
		// 지금 탐색을 시작하려는 i는 '나'에 해당하므로, 친구 관계에서 + 1을 해준다.
		// 총 5명의 친구 관계라면, 그 중 i는 이미 1명에 포함되어있다!!
		DFS(i, 1);

		// cnt == 5에 도달한 애가 있다면, for문 탈출
		if (arrive)
			break;
	}

	if (arrive)
		cout << 1;
	else
		cout << 0;

	return 0;
}

void DFS(int v, int cnt) {
	if (cnt == 5 || arrive) {
		arrive = true;
		return;
	}

	// visited 배열에 현재 노드 방문 기록
	visited[v] = true;

	// 인접리스트 방식이므로, j = 0일 때 부터 값들이 꽉꽉 차있음
	for (int j = 0; j < A[v].size(); j++) {
		int i = A[v][j];

		if (!visited[i]) {
			DFS(i, cnt + 1);
		}
	}

	// visited 배열에 현재 노드 방문 삭제
	// 해당 깊이까지 들어갔다가, 조건을 만족하지 않았던 애들을 다시 되돌려 놓는 작업
	// visited[v] = false; 를 수행하지 않으면, DFS 함수가 이전에 방문한 노드를 기록한 채로 탐색을 진행하게 되므로 생략하면 안됨!!
	visited[v] = false;
}