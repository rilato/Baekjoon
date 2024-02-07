// 현재 보고있는 좌표의 값을 업데이트하며 진행한다.
// DFS가 아닌 BFS를 사용하는 이유는, BFS는 해당 깊이에서 갈 수 있는 노드 탐색을 마친 후 다음 깊이로 넘어가기 때문이다.

// 2차원 배열로 문제가 주어지므로, 인접 리스트 방식이 아닌, 인접 행렬 방식을 사용한다.
// 인접 리스트 (2차원 벡터) : vector <vector <int>> A; 형식으로 표현
// 인접 행렬 (2차원 행렬) : int A[101][101]; 형식으로 표현

// 또한 방문 배열 역시, 문제에 맞게 2차원 배열을 사용한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int A[101][101] = { 0, };
bool visited[101][101] = { false, };

void BFS(int i, int j);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		// 수가 "붙어서" 입력으로 주어지므로, 문자열로 한 줄을 읽고 파싱하여 기록하도록 한다.
		string s;

		cin >> s;

		for (int j = 0; j < M; j++) {
			A[i][j] = s[j] - '0';
		}
	}

	// (0, 0)부터 탐색 시작
	BFS(0, 0);

	// 최종적으로 (N, M), 즉 (N - 1, M - 1)에 저장된 최소 값을 출력
	cout << A[N - 1][M - 1];

	return 0;
}

void BFS(int i, int j) {
	queue <pair <int, int>> q;

	q.push({ i, j });

	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;

		q.pop();

		visited[i][j] = true;

		// 상하좌우 탐색
		for (int k = 0; k < 4; k++) {
			int x = now_x + dx[k];	// 현재 보고있는 x좌표에서 제자리 및 좌우로 움직여보기
			int y = now_y + dy[k];	// 현재 보고있는 y좌표에서 제자리 및 상하로 움직여보기

			if (x >= 0 && x < N && y >= 0 && y < M) {	// 좌표의 유효성 검사
				if (A[x][y] != 0 && !visited[x][y]) {	// 다음에 방문할 좌표 중, 미방문 노드 검사
					visited[x][y] = true;
					A[x][y] = A[now_x][now_y] + 1;	// 깊이 업데이트
					q.push({ x, y });
				}
			}
		}
	}
}