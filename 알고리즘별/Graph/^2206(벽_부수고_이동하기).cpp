// 벽(1)에 대해, 해당 벽을 뚫었을 때에 대한 경로와, 뚫지 않았을 때에 대한 경로를 모두 나타내기 위해,
// visited 배열을 3차원 배열로 나타낸다!
// visited[x][y][0] : 벽을 한 번도 안부쉈을 때 방문 여부
// visited[x][y][1] : 벽을 한 번 부쉈을 때 방문 여부

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
string S[1001];
int map[1001][1001];
bool visited[1001][1001][2]; // 벽을 부쉈는지 여부를 확인하기 위해, visited를 3차원 배열로 나타냄. visited[x][y][벽을부순횟수].이미 방문한 정점이더라도, 벽을 부수고 왔는지, 벽을 부수지 않고 왔는지는 서로 다른 경로가 되기 때문에 저렇게 표현됨.
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

    // q는 (x좌표, y좌표, cnt값, 1을 몇 번 뚫었는지)가 담김
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

        // 최종 목적지에 도달했을 때의 경로 길이를 구함
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

            // 다음에 탐색할 곳이 벽이고, 아직 한 번도 벽을 뚫지 않았다면
            if (map[nextX][nextY] == 1 && wall == 0) {
                visited[nextX][nextY][wall + 1] = true;     // 벽의 개수 1 추가하고, 다음에 방문한 벽 방문 표시
                q.push({ nextX, nextY, tempCnt + 1, wall + 1 });     // 벽 뚫은 개수 + 1
            }
            // 다음에 탐색할 곳이 벽이 아니고, 해당 지점을 방문한 적이 없다면
            else if (map[nextX][nextY] == 0 && !visited[nextX][nextY][wall]) {
                visited[nextX][nextY][wall] = true;         // 다음에 방문한 벽 방문 표시
                q.push({ nextX, nextY, tempCnt + 1, wall });
            }
        }
    }

    // while문을 빠져나와 여기에 왔다는 것은, 벽을 두 번 이상 뚫었다는 것. 즉, 경로가 없다는 것.
    cout << "-1";

    return 0;
}