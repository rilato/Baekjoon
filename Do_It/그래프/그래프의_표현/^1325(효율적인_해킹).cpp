#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <vector <int>> A;
vector <int> answer;    // 각 노드를 탐색하면서, 탐색되는 노드들의 신뢰도를 증가시켜 저장하는 배열
vector <bool> visited;

void BFS(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    A.resize(n + 1);
    visited.resize(n + 1);
    answer.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        A[a].push_back(b);
    }

    for (int i = 0; i <= n; i++) {
        fill(visited.begin(), visited.end(), false);
        BFS(i);
    }

    int maximum = -1;

    for (int i = 1; i <= n; i++) {
        if (answer[i] > maximum) {
            maximum = answer[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (answer[i] == maximum) {
            cout << i << " ";
        }
    }

    return 0;
}

void BFS(int x) {
    queue <int> q;

    q.push(x);
    visited[x] = true;

    while (!q.empty()) {
        int now_x = q.front();
        q.pop();

        for (int j = 0; j < A[now_x].size(); j++) {
            int next_x = A[now_x][j];

            if (!visited[next_x]) {
                visited[next_x] = true;
                answer[next_x]++;
                q.push(next_x);
            }
        }
    }
}