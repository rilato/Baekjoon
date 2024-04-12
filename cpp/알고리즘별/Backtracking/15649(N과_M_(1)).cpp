// 백트래킹을 이용하여 순열을 구하는 문제이다.
// 조합을 구하는 문제는 15650을 풀어보도록 한다.

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> v;
vector <bool> visited;

void Backtracking(int depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	visited.resize(N + 1);

	Backtracking(0);

	return 0;
}

void Backtracking(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}

		cout << '\n';

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			Backtracking(depth + 1);
			v.pop_back();
			visited[i] = false;
		}
	}
}
