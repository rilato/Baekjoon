#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V, a, b;
vector <vector <int>> v;
vector <int> dfs;
vector <int> bfs;
vector <bool> dfsVisited;
vector <bool> bfsVisited;

void DFS(int now);
void BFS(int now);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    v.resize(N + 1);
    dfsVisited.resize(N + 1);
    bfsVisited.resize(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < v.size(); i++) {
        sort(v[i].begin(), v[i].end());
    }

    DFS(V);
    BFS(V);

    for (int i = 0; i < dfs.size(); i++) {
        cout << dfs[i] << " ";
    }

    cout << '\n';

    for (int i = 0; i < bfs.size(); i++) {
        cout << bfs[i] << " ";
    }

    return 0;
}

void DFS(int now) {
    dfs.push_back(now);
    dfsVisited[now] = true;

    if (dfs.size() == N) {
        return;
    }

    for (int i = 0; i < v[now].size(); i++) {
        if (!dfsVisited[v[now][i]]) {
            DFS(v[now][i]);
        }
    }
}

void BFS(int now) {
    queue <int> q;
    q.push(now);
    bfsVisited[now] = true;
    bfs.push_back(now);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int i = 0; i < v[vertex].size(); i++) {
            if (!bfsVisited[v[vertex][i]]) {
                bfsVisited[v[vertex][i]] = true;
                q.push(v[vertex][i]);
                bfs.push_back(v[vertex][i]);
            }
        }
    }
}