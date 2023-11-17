// ��(1)�� ����, �ش� ���� �վ��� ���� ���� ��ο�, ���� �ʾ��� ���� ���� ��θ� ��� ��Ÿ���� ����,
// visited �迭�� 3���� �迭�� ��Ÿ����!
// visited[x][y][0] : ���� �� ���� �Ⱥν��� �� �湮 ����
// visited[x][y][1] : ���� �� �� �ν��� �� �湮 ����

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
string S[1001];
int map[1001][1001];
bool visited[1001][1001][2]; // ���� �ν����� ���θ� Ȯ���ϱ� ����, visited�� 3���� �迭�� ��Ÿ��. visited[x][y][�����μ�Ƚ��].�̹� �湮�� �����̴���, ���� �μ��� �Դ���, ���� �μ��� �ʰ� �Դ����� ���� �ٸ� ��ΰ� �Ǳ� ������ ������ ǥ����.
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = S[i][j] - '0';
        }
    }

    // q�� (x��ǥ, y��ǥ, cnt��, 1�� �� �� �վ�����)�� ���
    queue <tuple <int, int, int, int>> q;
    q.push({ 0, 0, 1, 0 });
    visited[0][0][0] = true;

    while (!q.empty()) {
        tuple<int, int, int, int> temp = q.front();

        int tempX = get<0>(temp);
        int tempY = get<1>(temp);
        int tempCnt = get<2>(temp);
        int wall = get<3>(temp);

        q.pop();

        // ���� �������� �������� ���� ��� ���̸� ����
        if (tempX == N - 1 && tempY == M - 1) {
            cout << tempCnt;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = tempX + dx[i];
            int nextY = tempY + dy[i];

            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) {
                continue;
            }

            // ������ Ž���� ���� ���̰�, ���� �� ���� ���� ���� �ʾҴٸ�
            if (map[nextX][nextY] == 1 && wall == 0) {
                visited[nextX][nextY][wall + 1] = true;     // ���� ���� 1 �߰��ϰ�, ������ �湮�� �� �湮 ǥ��
                q.push({ nextX, nextY, tempCnt + 1, wall + 1 });     // �� ���� ���� + 1
            }
            // ������ Ž���� ���� ���� �ƴϰ�, �ش� ������ �湮�� ���� ���ٸ�
            else if (map[nextX][nextY] == 0 && !visited[nextX][nextY][wall]) {
                visited[nextX][nextY][wall] = true;         // ������ �湮�� �� �湮 ǥ��
                q.push({ nextX, nextY, tempCnt + 1, wall });
            }
        }
    }

    // while���� �������� ���⿡ �Դٴ� ����, ���� �� �� �̻� �վ��ٴ� ��. ��, ��ΰ� ���ٴ� ��.
    cout << "-1";

    return 0;
}