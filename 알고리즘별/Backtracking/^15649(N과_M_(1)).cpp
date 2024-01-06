#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> v;
vector <bool> visited;

void Backtracking(int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(M);
    visited.resize(N + 1);

    Backtracking(0);

    return 0;
}

void Backtracking(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << v[i] << ' ';
        }

        cout << '\n';

        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            v[depth] = i;
            visited[i] = true;
            Backtracking(depth + 1);
            visited[i] = false;
        }
    }
}