#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, a, b;
int arr[101][101];
int ans[101][101];
bool visited[101];

void BFS(int num);
void Check(int v);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        BFS(i);
        Check(i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}

void BFS(int num) {
    queue <int> q;
    q.push(num);
    // 자기 자신으로 돌아오는 것이 확정된 것이 아닌 방향이 있는 그래프이므로, 아래의 코드를 넣어주면 안된다!
    //visited[num] = true;

    while (!q.empty()) {
        int v = q.front();

        q.pop();

        for (int i = 0; i < N; i++) {
            if (!visited[i] && arr[v][i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void Check(int v) {
    for (int i = 0; i < N; i++) {
        if (visited[i] == 1) {
            ans[v][i] = 1;
            visited[i] = 0;
        }
    }
}