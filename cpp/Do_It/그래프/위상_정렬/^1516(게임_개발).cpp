// 위상 정렬
// 진입 차수란 자기 자신을 가리키는 노드의 개수

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector <vector <int>> v;	// 데이터 저장
vector <int> degree;	// 진입 차수 저장
vector <int> t;			// 각 노드마다 걸리는 시간 저장
vector <int> answer;	// 결과 저장
queue <int> q;			// 출력 순서를 위한 큐

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 1부터 N까지의 수를 index에 맞게 저장하기 위해 N + 1로 size 조정
	v.resize(N + 1);
	degree.resize(N + 1);
	t.resize(N + 1);
	answer.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int time, num;

		cin >> time >> num;

		// 건물을 짓기 위한 시간 저장
		t[i] = time;

		while (num != -1) {
			// 선행되는 num과 이어진 vector에 현재 보고있는 i값 넣기
			v[num].push_back(i);
			// i의 진입 차수 ++
			degree[i]++;

			cin >> num;
		}
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

		// 현재 선택된 값 (now)와 연결되어있는 모든 애들 조사
		for (int j = 0; j < v[now].size(); j++) {
			// 타겟 노드
			int next = v[now][j];

			// 타겟 노드의 진입 차수 1씩 차감
			degree[next]--;
			// 특정 건물을 짓기 위해서 걸리는 시간은
			// 해당 건물을 짓기 위해 우선적으로 지어야 하는 건물들 중에서 가장 오래 걸리는 시간 (answer[now]) + 특정 건물을 짓기 위해서 걸리는 시간 (t[now])
			answer[next] = max(answer[next], answer[now] + t[now]);

			// 진입 차수가 0이라면, 출력 대상이므로 q에 넣기
			if (degree[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << answer[i] + t[i] << '\n';
	}

	return 0;
}