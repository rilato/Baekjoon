// https://yabmoons.tistory.com/84

// "A�� �̹� ������ϱ� �� �̻� ������ϴ� !" �� �ƴ϶�
// "�ٸ� ��η� �ѹ� �����Կ�. 'A'�� ���� �ʾ����� �ٽ� �����ŵ� �˴ϴ�" ��� ������ �ڵ带 ��������� �Ѵ�.
// ���� ��Ʈ��ŷ ������� �����Ѵ�.

#include <iostream>
#include <queue>

using namespace std;

int R, C;
int maximum = 0;
char map[21][21];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool visited[26];

void DFS(int x, int y, int cnt);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }

    // �� ó�� 0,0 �湮 true�� ���� DFS Ž�� ����
    visited[map[0][0] - 'A'] = true;

    DFS(0, 0, 1);

    cout << maximum;

    return 0;
}

void DFS(int x, int y, int cnt) {
    maximum = max(maximum, cnt);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // nx�� �� ny�� ��
        if (0 <= nx && nx < R && 0 <= ny && ny < C && !visited[map[nx][ny] - 'A']) {
            visited[map[nx][ny] - 'A'] = true;
            DFS(nx, ny, cnt + 1);
            visited[map[nx][ny] - 'A'] = false;
        }
    }
}