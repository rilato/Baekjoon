// 위상 정렬
// 진입 차수란 자기 자신을 가리키는 노드의 개수

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector <vector <int>> v;	// 데이터 저장
vector <int> degree;	// 진입 차수 저장
queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// 1부터 N까지의 수를 index에 맞게 저장하기 위해 N + 1로 size 조정
	v.resize(N + 1);
	degree.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int S, E;

		cin >> S >> E;

		v[S].push_back(E);	// 노드 S 뒤에 노드 E를 연결
		degree[E]++;	// 진입 차수 배열에서, E는 S보다 순서가 밀리므로, 1 추가
	}

	for (int i = 1; i <= N; i++) {
		// 진입 차수 배열에서, 값이 0이라는 것은, 순서 상 가장 앞에 존재해야 한다는 것을 의미
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front();

		q.pop();

		cout << now << " ";

		// 현재 출력된 값 (now)와 연결되어있는 모든 애들 조사
		for (int j = 0; j < v[now].size(); j++) {
			int next = v[now][j];

			// 진입 차수 1씩 차감
			degree[next]--;

			// 진입 차수가 0이라면, 출력 대상이므로 q에 넣기
			if (degree[next] == 0) {
				q.push(next);
			}
		}

	}

	return 0;
}