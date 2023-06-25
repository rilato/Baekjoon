// dp인줄 알았으나 bfs
// 최단 경로를 구할 때 bfs를 사용한다

// https://hagisilecoding.tistory.com/20

#include <iostream>
#include <queue>

using namespace std;

int n, k;
bool visit[100001];
queue<pair<int, int>> q;

void bfs(int a);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    bfs(n);

    return 0;
}

void bfs(int a) {
    visit[a] = true;
    q.push(make_pair(a, 0));

    while (!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (x == k) {
            cout << cnt;
            break;
        }

        if (x + 1 >= 0 && x + 1 < 100001) {
            if (!visit[x + 1]) {
                visit[x + 1] = true;
                q.push(make_pair(x + 1, cnt + 1));
            }
        }

        if (x - 1 >= 0 && x - 1 < 100001) {
            if (!visit[x - 1]) {
                visit[x - 1] = true;
                q.push(make_pair(x - 1, cnt + 1));
            }
        }

        if (2 * x >= 0 && 2 * x < 100001) {
            if (!visit[2 * x]) {
                visit[2 * x] = true;
                q.push(make_pair(2 * x, cnt + 1));
            }
        }
    }
}