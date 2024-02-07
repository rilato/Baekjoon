// ���� �����ִ� ��ǥ�� ���� ������Ʈ�ϸ� �����Ѵ�.
// DFS�� �ƴ� BFS�� ����ϴ� ������, BFS�� �ش� ���̿��� �� �� �ִ� ��� Ž���� ��ģ �� ���� ���̷� �Ѿ�� �����̴�.

// 2���� �迭�� ������ �־����Ƿ�, ���� ����Ʈ ����� �ƴ�, ���� ��� ����� ����Ѵ�.
// ���� ����Ʈ (2���� ����) : vector <vector <int>> A; �������� ǥ��
// ���� ��� (2���� ���) : int A[101][101]; �������� ǥ��

// ���� �湮 �迭 ����, ������ �°� 2���� �迭�� ����Ѵ�.

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
		// ���� "�پ" �Է����� �־����Ƿ�, ���ڿ��� �� ���� �а� �Ľ��Ͽ� ����ϵ��� �Ѵ�.
		string s;

		cin >> s;

		for (int j = 0; j < M; j++) {
			A[i][j] = s[j] - '0';
		}
	}

	// (0, 0)���� Ž�� ����
	BFS(0, 0);

	// ���������� (N, M), �� (N - 1, M - 1)�� ����� �ּ� ���� ���
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

		// �����¿� Ž��
		for (int k = 0; k < 4; k++) {
			int x = now_x + dx[k];	// ���� �����ִ� x��ǥ���� ���ڸ� �� �¿�� ����������
			int y = now_y + dy[k];	// ���� �����ִ� y��ǥ���� ���ڸ� �� ���Ϸ� ����������

			if (x >= 0 && x < N && y >= 0 && y < M) {	// ��ǥ�� ��ȿ�� �˻�
				if (A[x][y] != 0 && !visited[x][y]) {	// ������ �湮�� ��ǥ ��, �̹湮 ��� �˻�
					visited[x][y] = true;
					A[x][y] = A[now_x][now_y] + 1;	// ���� ������Ʈ
					q.push({ x, y });
				}
			}
		}
	}
}