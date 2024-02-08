// 68번째 라인까지 중괄호가 너무 많아, 주의해서 코드를 작성해야 한다. 중괄호가 너무 많아질 경우, 함수로 바꿔서 푸는 것이 실수를 줄일 수 있다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K, V, E, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;

    while (K--) {
        bool flag = true;
        vector <vector <int>> v;
        vector <int> visited;
        queue <int> q;

        cin >> V >> E;

        v.resize(V + 1);
        visited.resize(V + 1);

        for (int i = 0; i < E; i++) {
            cin >> a >> b;

            v[a].push_back(b);
            v[b].push_back(a);
        }

        for (int i = 1; i <= V; i++) {
            // 1은 red, 2는 blue
            // red부터 탐색 시작
            int color = 1;

            if (!visited[i]) {
                visited[i] = color;
                q.push(i);

                while (!q.empty()) {
                    int now = q.front();
                    q.pop();

                    if (visited[now] == 1) {
                        color = 2;
                    }

                    else if (visited[now] == 2) {
                        color = 1;
                    }

                    for (int i = 0; i < v[now].size(); i++) {
                        int next = v[now][i];

                        if (!visited[next]) {
                            visited[next] = color;
                            q.push(next);
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= V; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                int next = v[i][j];

                // 현재 보고있는 노드와 다음 노드가 같은 색으로 칠해져있다면, false를 리턴
                if (visited[i] == visited[next]) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}