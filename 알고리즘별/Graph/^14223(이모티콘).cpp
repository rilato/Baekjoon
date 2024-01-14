#include <iostream>
#include <queue>

using namespace std;

int S;
// visited[a][b]의 의미는 "화면에 a개의 이모티콘이 있고, 클립보드에 b개의 이모티콘이 있는 상태" 를 의미하고
// 배열의 값이 true냐, false냐에 따라서 이미 탐색 했는지 안했는지를 결정함
bool visited[2001][2001];
// {{화면, 클립보드}, 시간}
queue <pair <pair <int, int>, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;

    // 맨 처음 화면에 있는 이모티콘 1개, 클립보드에 이모티콘 0개, 걸리는 시간 0초를 푸시
    q.push({ { 1, 0 }, 0 });
    visited[1][0] = true;   // visited[화면][클립보드]

    while (!q.empty()) {
        int screen = q.front().first.first;     // 화면에 표시된 이모티콘 개수
        int clipboard = q.front().first.second; // 클립보드에 있는 이모티콘 개수
        int time = q.front().second;            // 걸리는 시간

        q.pop();

        if (screen == S) {
            cout << time;
            break;
        }

        // 1번 조건 && 3번 조건의 배열 범위 초과 방지

        // 클립보드에 복사하려면, 화면에 표시된 이모티콘의 개수(screen)가 1개 이상이어야 하고,
        // 이 조건을 실행시키게 되면, 화면과 클립보드에 있는 이모티콘의 갯수는 (화면의 이모티콘 갯수, 화면의 이모티콘 갯수)가 될 것이다.
        // 왜냐하면, 클립보드에 이모티콘을 복사하면 이전에 클립보드에 있던 내용은 덮어쓰기 되기 때문이다.
        if (screen > 0 && screen * 2 <= 2000) {
            // 1번 조건 : 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
            // 클립보드에 화면에 있는 내용을 복사해서 저장하게 되면, 클립보드에 몇개의 이모티콘이 있었든지 상관 없이 덮어쓰기가 되므로,
            // 화면의 이모티콘 갯수가 그대로 클립보드로 저장되어지게 된다.
            if (!visited[screen][screen]) {
                visited[screen][screen] = true;
                q.push({ { screen, screen }, time + 1 });
            }
            // 3번 조건 : 화면에 있는 이모티콘 중 하나를 삭제한다.
            // 이 조건을 실행시키기 위해서는, 화면에 있는 이모티콘이 1개 이상이어야 한다.
            // 이 조건을 실행시키기 되면, 화면과 클립보드의 이모티콘 갯수는 (화면의 이모티콘 갯수 - 1, 클립보드의 이모티콘 갯수)가 된다.
            if (!visited[screen - 1][clipboard]) {
                visited[screen - 1][clipboard] = true;
                q.push({ {screen - 1, clipboard}, time + 1 });
            }
        }

        // 2번 조건의 배열 범위 초과 방지

        // 2번 조건 : 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
        // 이 조건을 실행시키기 위한 조건으로는, 클립보드에 이모티콘의 갯수가 1개 이상이어야 한다라는 것이다.
        // 이 조건을 실행하게 되면, 화면과 클립보드에 있는 이모티콘의 갯수는 ( 기존의 화면의 이모티콘 갯수 + 클립보드의 이모티콘 갯수, 클립보드의 이모티콘 갯수) 가 될 것이다.
        // 즉, 화면에는 기존의 상태에서 클립보드의 이모티콘 갯수만큼 추가가 되는 것이고, 클립보드에는 변동이 없다.
        if (clipboard > 0 && screen + clipboard <= 2000) {
            if (!visited[screen + clipboard][clipboard]) {
                visited[screen + clipboard][clipboard] = true;
                q.push({ {screen + clipboard, clipboard}, time + 1 });
            }
        }

    }

    return 0;
}