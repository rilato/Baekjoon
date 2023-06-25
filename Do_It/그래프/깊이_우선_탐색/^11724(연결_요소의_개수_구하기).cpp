// 연결된 각 부분을 세는 것이 아닌, 한 번에 쭉 연결된 것들이 몇 개 있는지 세는 문제이다.
// 따라서 방문했던 노드들에 대해 다시 visited[v] = false;로 되돌릴 필요가 없다.

// for each문 사용법을 익힌다.

#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> A;
vector <bool> visited;
void DFS(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, s, e;
	int cnt = 0;

	cin >> N >> M;

	// 1부터 1000을 담기 위해서는 0부터 1000까지의 배열, 즉 1001만큼이 필요하다. 따라서 N의 최대값 + 1 (1000 + 1)을 해준다.
	// 2차원 배열인 A 배열에서는, A 배열의 행의 사이즈를 재조정한다.
	A.resize(N + 1);
	visited = vector <bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		cin >> s >> e;

		A[s].push_back(e);
		A[e].push_back(s);
	}

	// 노드는 1 ~ N까지 이므로, 해당 노드들에 대해 탐색한다.
	for (int i = 1; i < N + 1; i++) {
		if (!visited[i]) {
			DFS(i);
			// 연결된 각 부분을 세는 것이 아닌, 한 번에 쭉 연결된 것들이 몇 개 있는지 세는 문제이므로,
			// DFS를 통해 i와 연결된 모든 애들을 묶어 한 개로 카운트한다.
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}

void DFS(int v) {
	// 해당 노드를 방문한 적이 있다면 리턴
	if (visited[v])
		return;

	visited[v] = true;

	// 현재 탐색중인 노드에 연결된 애들에 대해서 for-each문 사용
	//for (int i : A[v]) {
	//	if (!visited[i]) {
	//		DFS(i);
	//	}
	//}

	// 현재 탐색중인 노드에 연결된 애들에 대해서 for문 사용
	for (int j = 0; j < A[v].size(); j++) {
		int i = A[v][j];

		if (!visited[i]) {
			DFS(i);
		}
	}
}