// �̺� �׷����� ����� �� ��尡 ���� �ٸ� �� ���� ������ ��� ä�� �� �ִ� �׷����� �ǹ��Ѵ�.

#include <iostream>
#include <vector>
#include <queue>

// RED �Ǵ� BLUE�θ� �̷���� �־�� �̺� �׷���. ������ ��尡 ���� ������ ĥ�����ٸ�, �̴� �̺� �׷����� �ƴϴ�.
#define RED  1
#define BLUE 2

using namespace std;

int K, V, E; // �׽�Ʈ ���̽�, ���, ��ũ ����
vector <vector <int>> graph;
vector <int> visited;

void bfs(int start);
void dfs(int start);
bool isBipartiteGraph();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    while (K--) {
        cin >> V >> E;

        graph.resize(V + 1);
        visited.resize(V + 1);

        /* �׷��� ���� �Է� */
        for (int i = 0; i < E; i++) {
            int f, s;

            cin >> f >> s;

            graph[f].push_back(s);
            graph[s].push_back(f);
        }

        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                bfs(i);
                //dfs(i);
            }
        }

        /* �̺� �׷��� ���� üũ �� ������ */
        if (isBipartiteGraph()) {
            printf("YES\n");
        }

        else {
            printf("NO\n");
        }

        /* �׷��� �� �湮��� �ʱ�ȭ */
        for (int i = 0; i <= V; i++) {
            graph[i].clear();
            visited[i] = false;
        }
    }
    return 0;
}

void bfs(int start) {
    queue<int> q;

    int color = RED; // ���� ����� default ������ RED.

    visited[start] = color;
    q.push(start);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        // ���� ���� �ݴ�Ǵ� ����� �ٲ����
        if (visited[now] == RED) {
            color = BLUE;
        }

        else if (visited[now] == BLUE) {
            color = RED;
        }

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (!visited[next]) {
                visited[next] = color;
                q.push(next);
            }
        }
    }
}

void dfs(int start) {
    if (!visited[start]) {
        visited[start] = RED;
    }

    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];

        if (!visited[next]) {
            if (visited[start] == RED) {
                visited[next] = BLUE;
            }

            else if (visited[start] == BLUE) {
                visited[next] = RED;
            }

            dfs(next);
        }
    }
}

bool isBipartiteGraph() {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int next = graph[i][j];

            // ���� �����ִ� ���� ���� ��尡 ���� ������ ĥ�����ִٸ�, false�� ����
            if (visited[i] == visited[next]) {
                return false;
            }
        }
    }

    return true;
}