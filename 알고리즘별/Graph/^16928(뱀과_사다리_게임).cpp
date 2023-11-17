#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[101];
bool visited[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    // 사다리 입력, 뱀 입력
    for (int i = 0; i < n + m; i++) {
        int u, v;

        cin >> u >> v;

        map[u] = v;
    }

    queue<pair<int, int>> q;

    // 맨 처음, 시작점은 1, 카운트는 0
    q.push({ 1, 0 });

    while (!q.empty()) {
        int x = q.front().first;    // 현재 보고있는 좌표
        int cnt = q.front().second; // 카운트 수

        q.pop();

        for (int i = 1; i <= 6; i++) {
            int nextX = x + i;  // 다음에 살펴봐야할 좌표

            if (nextX == 100) {     // 도착 시, cnt + 1을 출력
                cout << cnt + 1;
                return 0;
            }
            else if (nextX < 100) {     // 100보다 작고, 도착 안했을 경우
                if (map[nextX] != 0) {  // 사다리가 있는지 먼저 확인
                    nextX = map[nextX]; // 사다리가 있다면, 다음에 살펴봐야할 좌표를 업데이트
                }
                if (!visited[nextX]) {  // 다음에 살펴봐야할 좌표를 방문하지 않았다면, 해당 좌표와 cnt + 1을 큐에 푸시
                    q.push({ nextX, cnt + 1 });
                    visited[nextX] = true;
                }
            }
        }
    }

    return 0;
}