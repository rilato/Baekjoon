// 아무 노드에서 가장 먼 노드를 찾은 후 그 노드에서 가장 먼 노드를 찾으면 트리의 지름이 된다
// 잎에서 루트까지의 거리중에서 최대가 트리의 지름이 아닌경우도 있다.
// 다른 말로 하면, 트리의 지름은 잎에서 잎까지의 거리일수도 있다.


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, node, E, V;
vector <vector <pair <int, int>>> A;
vector <bool> visited;
vector <int> dist;

void BFS(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	A.resize(N + 1);	// 0번째 index는 사용하지 않으므로, 100,000개를 맞추기 위해서는 배열의 크기를 N + 1로 설정한다.

	for (int i = 0; i < N; i++) {
		// 노드 번호 입력
		cin >> node;

		while (1) {
			cin >> E;

			if (E == -1)
				break;

			cin >> V;

			A[node].push_back({ E, V });
		}
	}

	dist = vector <int>(N + 1, 0);	// 거리 배열 초기화
	visited = vector <bool>(N + 1, 0);	// 방문 배열 초기화

	// Max 노드를 찾기 위한 BFS
	BFS(1);	// 1. 아무 노드(1)에서 가장 먼 노드를 찾는다.

	// 인덱스 1부터 데이터가 들어가므로, max_idx는 1부터 시작하도록 한다.
	// 단, 0부터 시작해도 정답은 맞다.
	int Max = 1;

	// Max 노드 찾는 작업
	// for문을 0부터 시작해도 정답은 맞다.
	for (int i = 2; i <= N; i++) {
		// dist[i - 1]과 dist[i]를 비교하는 식으로 해결하면 안된다!
		// 그렇게 되면, i를 인덱스로 갖는 dist값이 i - 1보다 크기만 하면 idx가 업데이트 되므로, idx가 최대값이 아닐 수 있기 때문이다!!
		// max_idx와 i를 비교해야한다!
		if (dist[Max] < dist[i]) {
			Max = i;
		}
	}

	fill(dist.begin(), dist.end(), 0); 	// 거리 배열 초기화
	fill(visited.begin(), visited.end(), false);	// 방문 배열 초기화

	// Max 노드에서 가장 먼 것을 찾기 위한 BFS
	// 아무 노드에서 가장 먼 노드를 찾은 후 (Max) 그 노드에서 가장 먼 노드를 찾으면 트리의 지름이 된다
	BFS(Max);	// 거리 배열에서 가장 큰 값을 다시 시작점으로 지정 (새로운 시작점으로 실행)
	sort(dist.begin(), dist.end());

	cout << dist[N];	// dist배열에서 가장 큰 값을 정답으로 출력

	return 0;
}

void BFS(int v) {
	queue <int> q;
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		int now_node = q.front();
		q.pop();

		for (int j = 0; j < A[now_node].size(); j++) {
			int i = A[now_node][j].first;

			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
				dist[i] = dist[now_node] + A[now_node][j].second;				// 거리 배열 업데이트
			}
		}
	}
}