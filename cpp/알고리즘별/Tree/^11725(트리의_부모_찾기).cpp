// 트리와 관련된 문제이지만, BFS로 해결한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, n1, n2;
vector <bool> visited;
vector <vector <int>> v;
vector <int> answer;
queue <int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    visited.resize(N + 1);
    v.resize(N + 1);
    answer.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2;

        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < v[parent].size(); i++) {
            int child = v[parent][i];

            if (!visited[child]) {
                visited[child] = true;
                answer[child] = parent;
                q.push(child);
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}
