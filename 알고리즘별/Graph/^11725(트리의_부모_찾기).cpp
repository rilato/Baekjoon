// https://iridescent-zeal.tistory.com/38

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, a, b;
vector <int> v[100001];
int ans[100001];    // 인덱스는 자식에 해당, 값은 부모에 해당
bool visited[100001];
queue <int> q;

void BFS(int num);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    BFS(1);

    for (int i = 2; i <= N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}

void BFS(int num) {
    q.push(num);
    visited[num] = true;

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < v[parent].size(); i++) {
            int child = v[parent][i];

            if (!visited[child]) {
                visited[child] = true;
                ans[child] = parent;
                q.push(child);
            }
        }
    }
}