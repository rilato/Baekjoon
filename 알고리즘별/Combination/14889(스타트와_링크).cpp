#include <iostream>
#include <vector>

using namespace std;

int N;
int answer = 1000000000;
vector <vector <int>> v;
vector <int> combine;	// ��ŸƮ ������ ������ ������ ã�´�.
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

	// ��ŸƮ ������ ������ ������ N / 2�� �̹Ƿ�, ������ ����� �������Ѵ�.
	combine.resize(N / 2);
	visited.resize(N);

	// 0���� N - 1���� N���� �� ��, N/2������ ���� ������ ã�´�.
	combination(0, 0);

	cout << answer;

	return 0;
}

void combination(int num, int depth) {
	if (depth == N / 2) {
		int startTeam = 0;
		int linkTeam = 0;

		vector <int> linkTeamIdx;

		// �湮���� ���� ���� �� ��ũ ���� �ε����̴�.
		for (int i = 0; i < visited.size(); i++) {
			if (!visited[i]) {
				linkTeamIdx.push_back(i);
			}
		}

		// ��ŸƮ ���� �ɷ�ġ �հ踦 ��� ���Ѵ�.
		for (int i = 0; i < combine.size(); i++) {
			for (int j = 0; j < combine.size(); j++) {
				startTeam += v[combine[i]][combine[j]];
			}
		}

		// ��ũ ���� �ɷ�ġ �հ踦 ��� ���Ѵ�.
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