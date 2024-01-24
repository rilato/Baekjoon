#include <iostream>
#include <queue>

using namespace std;

int N, K;
int arr[100001];
bool visited[100001];
queue <pair <int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    q.push({ N, 0 });
    visited[N] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();

        if (x == K) {
            cout << time;
            break;
        }

        if (x * 2 >= 0 && x * 2 <= 100000 && !visited[x * 2]) {
            visited[x * 2] = true;
            q.push({ x * 2, time });
        }
        if (x - 1 >= 0 && !visited[x - 1]) {
            visited[x - 1] = true;
            q.push({ x - 1, time + 1 });
        }
        if (x + 1 <= 100000 && !visited[x + 1]) {
            visited[x + 1] = true;
            q.push({ x + 1, time + 1 });
        }
    }

    return 0;
}