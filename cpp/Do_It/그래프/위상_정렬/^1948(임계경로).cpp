// 위상 정렬
// 진입 차수란 자기 자신을 가리키는 노드의 개수

// 출발 도시와 도착 도시가 주어지기 때문에 일반적인 위상 정렬이 아닌, 시작점을 출발 도시로 지정하고 위상 정렬을 수행해야 함.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, e, t;			// s : start, e : end, t : time
vector <vector <pair<int, int>>> A;		// 데이터 저장 배열
vector <vector <pair<int, int>>> reverseA;	// 역방향 인접 리스트 데이터 저장 배열
vector <int> degree;		// 진입 차수 배열
vector <int> answer;
queue <int> q;				// 위상 정렬을 수행할 큐

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	A.resize(n + 1);
	reverseA.resize(n + 1);
	degree.resize(n + 1);
	answer.resize(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> s >> e >> t;

		A[s].push_back({ e, t });
		reverseA[e].push_back({ s, t });	// 역방향 에지 정보 저장
		degree[e]++;	// 진입 차수 배열 + 1
	}

	int start, end;

	cin >> start >> end;

	// 위상 정렬

	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int j = 0; j < A[now].size(); j++) {
			pair<int, int> next = A[now][j];

			degree[next.first]--;

			answer[next.first] = max(answer[next.first], answer[now] + next.second);

			if (degree[next.first] == 0) {
				q.push(next.first);
			}
		}
	}

	// 위상 정렬 reverse

	int cnt = 0;			// 1분도 쉬지 않고 달려야 하는 도로의 수
	vector <bool> visited;	// 각 도시의 방문 배열 저장
	visited.resize(n + 1);
	queue <int> rq;

	rq.push(e);				// 도착 도시 큐에 삽입

	while (!rq.empty()) {
		int now = rq.front();
		rq.pop();

		for (int j = 0; j < reverseA[now].size(); j++) {
			// 1분도 쉬지 않는 도로 체크
			pair <int, int> next = reverseA[now][j];

			if (answer[next.first] + next.second == answer[now]) {
				// 쉬지 않고 달려야하는 도로 수 1 추가
				cnt++;
				// 중복 카운트 방지를 위해 이미 방문한 노드 제외
				if (visited[next.first] == false) {
					visited[next.first] = true;
					rq.push(next.first);
				}
			}
		}
	}

	cout << answer[end] << '\n' << cnt;

	return 0;
}