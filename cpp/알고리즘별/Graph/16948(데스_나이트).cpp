#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, sr, sc, fr, fc;
vector <vector <int>> v;
queue <pair <int, int>> q;
int dr[6] = { -2, -2, 0, 0, 2, 2 };
int dc[6] = { -1, 1, -2, 2, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> sr >> sc >> fr >> fc;

	v.resize(N, vector <int>(N));

	q.push({ sr, sc });
	
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;

		q.pop();

		if (r == fr && c == fc) {
			cout << v[r][c];
			return 0;
		}

		for (int i = 0; i < 6; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
				continue;
			}

			if (v[nr][nc] == 0) {
				q.push({ nr, nc });
				v[nr][nc] = v[r][c] + 1;
			}
		}
	}

	cout << -1;

	return 0;
}
