// 트리는 두 노드를 단순하게 연결하므로, 데이터를 v에 저장할 때 양 방향으로 저장한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, n1, n2;
vector <vector <int>> v;
vector <bool> visited;
vector <int> answer;
queue <int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N + 1);
    visited.resize(N + 1);
    answer.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2;

        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int parentNode = q.front();
        q.pop();

        for (int i = 0; i < v[parentNode].size(); i++) {
            int childNode = v[parentNode][i];

            if (!visited[childNode]) {
                visited[childNode] = true;
                q.push(childNode);
                answer[childNode] = parentNode;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}
