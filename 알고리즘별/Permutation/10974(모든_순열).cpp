// 모든 순열을 구하는 문제로, N과 M (1)과 동일한 문제다.

#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v;
vector <int> visited;

void permutation(int depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	v.resize(N);
	visited.resize(N + 1);

	permutation(0);

	return 0;
}

void permutation(int depth) {
	if (depth == N) {
		for (int i = 0; i < N; i++) {
			cout << v[i] << " ";
		}

		cout << '\n';

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			v[depth] = i;
			visited[i] = true;
			permutation(depth + 1);
			visited[i] = false;
		}
	}
}