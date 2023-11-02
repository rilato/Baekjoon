#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, start, end;
	vector <vector <pair <int, int>>> A;
	vector <bool> visited;
	priority_queue <pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> pq;
	vector <int> distance;

	cin >> N >> M;

	A.resize(N + 1);
	visited.resize(N + 1);
	distance.resize(N + 1);

	// 그래프 저장
	for (int i = 0; i < M; i++) {
		int s, e, w;

		cin >> s >> e >> w;

		A[s].push_back({ e, w });
	}

	// 출발 지점, 도착 지점 입력
	cin >> start >> end;

	// 거리 배열 초기화
	for (int i = 0; i <= N; i++) {
		distance[i] = 2000000000;
	}

	distance[start] = 0;
	// start와, start의 distance[start]값을 푸시
	// 비용 기준 정렬을 위해, 데이터 순서를 {비용, 노드}로 설정
	pq.push({ 0, start });

	while (!pq.empty()) {
		pair<int, int> temp = pq.top();
		pq.pop();
		int temp_node = temp.second;

		// 해당 노드를 방문한 적이 있으면, 건너 뛰기
		if (visited[temp_node])
			continue;

		visited[temp_node] = true;

		for (int i = 0; i < A[temp_node].size(); i++) {
			int next_node = A[temp_node][i].first;
			int weight = A[temp_node][i].second;

			// 현재 노드의 거리 + 다음 노드까지의 가중치 < 다음 노드의 최단 거리라면, 값 업데이트
			if (distance[temp_node] + weight < distance[next_node]) {
				distance[next_node] = distance[temp_node] + weight;
				pq.push({ distance[next_node], next_node });
			}
		}
	}

	cout << distance[end];

	return 0;
}