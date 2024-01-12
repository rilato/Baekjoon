#include <iostream>
#include <vector>

using namespace std;

int N;
int answer = 1000000000;
vector <vector <int>> v;
vector <int> combine;	// 스타트 팀으로 가능한 조합을 찾는다.
vector <bool> visited;

void combination(int num, int depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N, vector <int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	// 스타트 팀으로 가능한 조합은 N / 2개 이므로, 벡터의 사이즈를 재조정한다.
	combine.resize(N / 2);
	visited.resize(N);

	// 0부터 N - 1까지 N개의 수 중, N/2가지를 고르는 조합을 찾는다.
	combination(0, 0);

	cout << answer;

	return 0;
}

void combination(int num, int depth) {
	if (depth == N / 2) {
		int startTeam = 0;
		int linkTeam = 0;

		vector <int> linkTeamIdx;

		// 방문하지 않은 곳이 곧 링크 팀의 인덱스이다.
		for (int i = 0; i < visited.size(); i++) {
			if (!visited[i]) {
				linkTeamIdx.push_back(i);
			}
		}

		// 스타트 팀의 능력치 합계를 모두 구한다.
		for (int i = 0; i < combine.size(); i++) {
			for (int j = 0; j < combine.size(); j++) {
				startTeam += v[combine[i]][combine[j]];
			}
		}

		// 링크 팀의 능력치 합계를 모두 구한다.
		for (int i = 0; i < linkTeamIdx.size(); i++) {
			for (int j = 0; j < linkTeamIdx.size(); j++) {
				linkTeam += v[linkTeamIdx[i]][linkTeamIdx[j]];
			}
		}

		if (abs(startTeam - linkTeam) < answer) {
			answer = abs(startTeam - linkTeam);
		}

		return;
	}

	for (int i = num; i < N; i++) {
		if (!visited[i]) {
			combine[depth] = i;
			visited[i] = true;
			combination(i + 1, depth + 1);
			visited[i] = false;
		}
	}
}