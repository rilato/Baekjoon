#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, I, startI, startJ, finishI, finishJ;
int dr[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dc[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		vector <vector <int>> chess;
		vector <vector <bool>> visited;
		queue <pair <int, int>> q;

		cin >> I >> startI >> startJ >> finishI >> finishJ;

		chess.resize(I, vector <int>(I));
		visited.resize(I, vector <bool>(I));

		q.push({ startI, startJ });
		visited[startI][startJ] = true;

		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;

			q.pop();

			if (r == finishI && c == finishJ) {
				cout << chess[r][c] << '\n';
				break;
			}

			for (int i = 0; i < 8; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nc < 0 || nr >= I || nc >= I) {
					continue;
				}

				if (!visited[nr][nc]) {
					chess[nr][nc] = chess[r][c] + 1;
					visited[nr][nc] = true;
					q.push({ nr, nc });
				}
			}
		}
	}

	return 0;
}
