// https://yabmoons.tistory.com/84

// "A는 이미 밟았으니까 더 이상 못밟습니다 !" 가 아니라
// "다른 경로로 한번 가볼게요. 'A'는 밟지 않았으니 다시 밟으셔도 됩니다" 라는 식으로 코드를 구현해줘야 한다.
// 따라서 백트래킹 방식으로 구현한다.

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

    // 맨 처음 0,0 방문 true로 놓고 DFS 탐색 시작
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

        // nx가 행 ny가 열
        if (0 <= nx && nx < R && 0 <= ny && ny < C && !visited[map[nx][ny] - 'A']) {
            visited[map[nx][ny] - 'A'] = true;
            DFS(nx, ny, cnt + 1);
            visited[map[nx][ny] - 'A'] = false;
        }
    }
}