// Backtracking을 시도할 때, 맨 처음 넣는 원소에 대해 방문처리한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, a, b;
vector <vector <int>> v;
vector <bool> visited;
bool flag = false;

void Backtracking(int num, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(N);
    visited.resize(N);

    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        // 맨 처음 들어가는 숫자 i를 방문 처리 해주어야 한다.
        // Backtracking 함수에서는 i를 방문처리 안하기 때문. i의 원소에 대해서만 살펴볼 뿐임.
        visited[i] = true;

        Backtracking(i, 0);

        visited[i] = false;

        if (flag) {
            break;
        }
    }

    if (flag) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}

void Backtracking(int num, int depth) {
    // 깊이가 4라는 것은, A B C D E가 친구 관계로 이어져있다는 것이다.
    if (depth == 4) {
        flag = true;
        return;
    }

    // num이 갖고 있는 원소들에 대하여 방문을 조사하고, 더 깊이 들어간다.
    for (int i = 0; i < v[num].size(); i++) {
        if (!visited[v[num][i]]) {
            visited[v[num][i]] = true;
            Backtracking(v[num][i], depth + 1);
            visited[v[num][i]] = false;
        }
    }
}
