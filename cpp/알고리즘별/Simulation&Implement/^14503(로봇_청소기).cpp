// 청소기가 멈추려면 1.범위를 벗어나거나, 2.벽을 만나면 종료한다.
// v에 입력되는 값 중 1은 벽이다.
// 따라서 청소했음을 1로 표시해서는 안된다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, a, b, d;
int cnt = 0;
// 북 동 남 서 모두 반시계 방향에 맞게 row, col을 설정
// 북
int ndr[4] = { 0, 1, 0, -1 };
int ndc[4] = { -1, 0, 1, 0 };
// 동
int edr[4] = { -1, 0, 1, 0 };
int edc[4] = { 0, -1, 0, 1 };
// 남
int sdr[4] = { 0, -1, 0, 1 };
int sdc[4] = { 1, 0, -1, 0 };
// 서
int wdr[4] = { 1, 0, -1, 0 };
int wdc[4] = { 0, 1, 0, -1 };
vector <vector <int>> v;
queue <pair <pair<int, int>, int>> q;

void BFS(int row, int col, int direction);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> a >> b >> d;

	v.resize(N, vector <int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	BFS(a, b, d);

	return 0;
}

void BFS(int row, int col, int direction) {
	if (v[row][col] == 0) {
		v[row][col] = 2;	// 청소했음으로 처리해주기
		cnt++;
	}

	q.push({ { row, col }, direction });

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int d = q.front().second;

		//cout << "(r, c, d) : " << r << ", " << c << ", " << d << '\n';

		q.pop();

		// 범위 벗어나는 애가 있다면, 또는 현재 위치가 벽이라면 출력 후 종료
		if (r < 0 || c < 0 || r >= N || c >= M || v[r][c] == 1) {
			cout << cnt;
			break;
		}

		// 북을 바라보고 있는 경우
		if (d == 0) {
			bool flag = true;
			// i == 0 : 서, i == 1 : 남, i == 2 : 동, i == 3 : 북
			for (int i = 0; i < 4; i++) {
				int nr = ndr[i] + r;
				int nc = ndc[i] + c;
				int nd;

				if (flag && nr >= 0 && nc >= 0 && nr < N && nc < M && v[nr][nc] == 0) {
					flag = false;
					v[nr][nc] = 2;	// 청소했음으로 처리해주기
					cnt++;

					if (i == 0) {
						nd = 3;
					}
					else if (i == 1) {
						nd = 2;
					}
					else if (i == 2) {
						nd = 1;
					}
					else if (i == 3) {
						nd = 0;
					}

					q.push({ {nr, nc}, nd });
				}

				// 네 방향 모두 탐색했는데 청소할 칸이 없으면 방향 유지한 채로 한 칸 후진
				if (i == 3 && flag) {
					q.push({ {r + 1, c}, d });
				}
			}
		}
		// 동을 바라보고 있는 경우
		else if (d == 1) {
			bool flag = true;
			// i == 0 : 북, i == 1 : 서, i == 2 : 남, i == 3 : 동
			for (int i = 0; i < 4; i++) {
				int nr = edr[i] + r;
				int nc = edc[i] + c;
				int nd;

				if (flag && nr >= 0 && nc >= 0 && nr < N && nc < M && v[nr][nc] == 0) {
					flag = false;
					v[nr][nc] = 2;	// 청소했음으로 처리해주기
					cnt++;

					if (i == 0) {
						nd = 0;
					}
					else if (i == 1) {
						nd = 3;
					}
					else if (i == 2) {
						nd = 2;
					}
					else if (i == 3) {
						nd = 1;
					}

					q.push({ {nr, nc}, nd });
				}

				// 네 방향 모두 탐색했는데 청소할 칸이 없으면 방향 유지한 채로 한 칸 후진
				if (i == 3 && flag) {
					q.push({ {r, c - 1}, d });
				}
			}
		}
		// 남을 바라보고 있는 경우
		else if (d == 2) {
			bool flag = true;
			// i == 0 : 동, i == 1 : 북, i == 2 : 서, i == 3 : 남
			for (int i = 0; i < 4; i++) {
				int nr = sdr[i] + r;
				int nc = sdc[i] + c;
				int nd;

				if (flag && nr >= 0 && nc >= 0 && nr < N && nc < M && v[nr][nc] == 0) {
					flag = false;
					v[nr][nc] = 2;	// 청소했음으로 처리해주기
					cnt++;

					if (i == 0) {
						nd = 1;
					}
					else if (i == 1) {
						nd = 0;
					}
					else if (i == 2) {
						nd = 3;
					}
					else if (i == 3) {
						nd = 2;
					}

					q.push({ {nr, nc}, nd });
				}

				// 네 방향 모두 탐색했는데 청소할 칸이 없으면 방향 유지한 채로 한 칸 후진
				if (i == 3 && flag) {
					q.push({ {r - 1, c}, d });
				}
			}
		}
		// 서를 바라보고 있는 경우
		else if (d == 3) {
			bool flag = true;
			// i == 0 : 남, i == 1 : 동, i == 2 : 북, i == 3 : 서
			for (int i = 0; i < 4; i++) {
				int nr = wdr[i] + r;
				int nc = wdc[i] + c;
				int nd;

				if (flag && nr >= 0 && nc >= 0 && nr < N && nc < M && v[nr][nc] == 0) {
					flag = false;
					v[nr][nc] = 2;	// 청소했음으로 처리해주기
					cnt++;

					if (i == 0) {
						nd = 2;
					}
					else if (i == 1) {
						nd = 1;
					}
					else if (i == 2) {
						nd = 0;
					}
					else if (i == 3) {
						nd = 3;
					}

					q.push({ {nr, nc}, nd });
				}

				// 네 방향 모두 탐색했는데 청소할 칸이 없으면 방향 유지한 채로 한 칸 후진
				if (i == 3 && flag) {
					q.push({ {r, c + 1}, d });
				}
			}
		}
	}
}
