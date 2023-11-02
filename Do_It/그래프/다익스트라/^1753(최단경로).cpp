#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K, u, v, w;
	vector <vector <pair <int, int>>> A;		// 출발점마다 {도착점, 에지의 가중치}를 저장 (2차원 벡터)
	vector <int> distance;			// 최단 경로 거리를 저장할 벡터
	vector <bool> visited;			// 노드 사용 여부 저장
	// priority_queue는 기본적으로 가장 큰 값부터 Top()으로 배출함.
	// 다익스트라에서, 가장 작은 값부터 배출하기 위해, priority_queue의 인자를 세 개로 넣고, greater를 씀.
	priority_queue<pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> pq;		// 다익스트라 알고리즘 수행을 위한 우선순위 큐(오름차순 정렬)

	cin >> V >> E >> K;

	A.resize(V + 1);
	distance.resize(V + 1);
	visited.resize(V + 1);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		A[u].push_back({ v, w });
	}

	// 최단 경로 거리 벡터 초기화
	for (int i = 0; i <= V; i++) {
		distance[i] = 2147000000;
	}

	distance[K] = 0;	// 출발 지점의 distance는 0으로 초기화
	pq.push({ 0, K });	// 출발 노드를 우선순위 큐에 넣고 시작. 우선순위 큐는 ({ 해당 노드의 distance값, 해당 노드 })로 구성

	while (!pq.empty()) {
		pair<int, int> temp = pq.top();
		pq.pop();

		int temp_vertex = temp.second;	// 현재 선택한 노드

		// 현재 선택한 노드를 방문한 적이 있는지 확인
		if (visited[temp_vertex]) {
			// 이미 방문한 노드는 다시 큐에 넣지 않음
			continue;
		}

		// 현재 노드를 방문 노드로 업데이트
		visited[temp_vertex] = true;

		// 현재 선택 노드의 에지 개수만큼 iterate
		for (int i = 0; i < A[temp_vertex].size(); i++) {
			pair<int, int> tmp = A[temp_vertex][i];
			int next = tmp.first;	// 연결된 다음 노드
			int value = tmp.second;	// 에지 값

			// 타깃 노드를 방문하지 않았고 현재 선택 노드 최단 거리 + 비용 < 타깃 노드의 최단거리인 경우, 업데이트 진행
			if (distance[temp_vertex] + value < distance[next]) {
				distance[next] = value + distance[temp_vertex];
				pq.push({ distance[next], next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (visited[i])
			cout << distance[i] << '\n';
		else
			cout << "INF" << '\n';
	}

	return 0;
}