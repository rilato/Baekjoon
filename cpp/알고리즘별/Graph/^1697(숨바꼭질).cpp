// dp인줄 알았으나 bfs
// 최단 경로를 구할 때 bfs를 사용한다

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
queue <pair <int, int>> q;
bool visited[100001] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    q.push({ N, 0 });
    visited[N] = true;

    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (now == K) {
            cout << cnt;
            break;
        }

        // N에서 하나씩 뻗어나갈 때 마다, 모든 경우를 체크하기 위해서 else if를 사용하지 않고, if문을 사용한다!
        if (now - 1 >= 0 && !visited[now - 1]) {
            q.push({ now - 1, cnt + 1 });
            visited[now - 1] = true;
        }
        if (now + 1 <= 100000 && !visited[now + 1]) {
            q.push({ now + 1, cnt + 1 });
            visited[now + 1] = true;
        }
        if (now * 2 <= 100000 && !visited[now * 2]) {
            q.push({ now * 2, cnt + 1 });
            visited[now * 2] = true;
        }

        /*
        * 아래의 코드는, visited[now - 1]을 먼저 검사하기 때문에, out of bound가 발생할 수 있다!
        * 이를 막기 위해, 위의 코드 처럼, now - 1 >= 0을 먼저 검사한 후, visited[now - 1]을 검사하도록 한다.
        if (!visited[now - 1] && now - 1 >= 0) {
            q.push({ now - 1, cnt + 1 });
            visited[now - 1] = true;
        }
        if (!visited[now + 1] && now + 1 <= 100000) {
            q.push({ now + 1, cnt + 1 });
            visited[now + 1] = true;
        }
        if (!visited[now * 2] && now * 2 <= 100000) {
            q.push({ now * 2, cnt + 1 });
            visited[now * 2] = true;
        }
        */
    }

    return 0;
}