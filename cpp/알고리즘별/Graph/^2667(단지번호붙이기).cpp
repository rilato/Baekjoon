#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int cnt = 0;
string arr[26];
bool visited[26][26];
int move_x[4] = { -1, 1, 0, 0 };
int move_y[4] = { 0, 0, -1, 1 };
vector <int> v;
queue <pair <int, int>> q;

void BFS(int x, int y);
void DFS(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '1' && !visited[i][j]) {
				cnt = 0;
				//BFS(i, j);
				DFS(i, j);
				v.push_back(cnt);
			}
		}
	}

	cout << v.size() << '\n';

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';

	return 0;
}

void BFS(int x, int y) {
	q.push({ x, y });
	visited[x][y] = 1;
	cnt++;

	while (!q.empty()) {
		int temp_x = q.front().first;
		int temp_y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = temp_x + move_x[i];
			int next_y = temp_y + move_y[i];

			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N && !visited[next_x][next_y] && arr[next_x][next_y] == '1') {
				q.push({ next_x, next_y });
				visited[next_x][next_y] = true;
				cnt++;
			}
		}
	}
}

void DFS(int x, int y) {
	visited[x][y] = 1;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int next_x = x + move_x[i];
		int next_y = y + move_y[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
			continue;

		if (arr[next_x][next_y] == '1' && !visited[next_x][next_y]) {
			DFS(next_x, next_y);
		}
	}
}