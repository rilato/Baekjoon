// 반례
// 2
// -1 0
// 1

// 답 : 1 / 내 답 : 0

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, num, root, delNum;
int cnt = 0;
vector <vector <int>> v;
vector <bool> visited;
queue <int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> num;

        // -1은 루트노드
        if (num == -1) {
            root = i;
        }
        else {
            v[num].push_back(i);
        }
    }

    cin >> delNum;

    if (delNum == root) {
        cout << 0;
        return 0;
    }

    q.push(root);
    visited[root] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (v[node].empty()) {
            cnt++;
        }

        else {
            for (int i = 0; i < v[node].size(); i++) {
                if (v[node][i] == delNum) {
                    continue;
                }
                else {
                    if (!visited[v[node][i]]) {
                        visited[v[node][i]] = true;
                        q.push(v[node][i]);
                    }
                }
            }
        }
    }

    cout << cnt;

    return 0;
}

// 옳은 풀이

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, num, root, delNum;
int cnt = 0;
vector <vector <int>> v;
vector <bool> visited;
queue <int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> num;

        // -1은 루트노드
        if (num == -1) {
            root = i;
        }
        else {
            v[num].push_back(i);
        }
    }

    cin >> delNum;

    if (delNum == root) {
        cout << 0;
        return 0;
    }

    q.push(root);
    visited[root] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        int childNode = 0;

        for (int i = 0; i < v[node].size(); i++) {
            if (v[node][i] == delNum) {
                continue;
            }
            else {
                if (!visited[v[node][i]]) {
                    visited[v[node][i]] = true;
                    q.push(v[node][i]);
                    childNode++;
                }
            }
        }

        if (childNode == 0) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
