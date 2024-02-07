// 순열 구하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector <int> v;
vector <int> answer;
vector <bool> visited;

void Backtracking(int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    Backtracking(0);

    return 0;
}

void Backtracking(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << " ";
        }

        cout << '\n';

        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            answer.push_back(v[i]);
            Backtracking(depth + 1);
            answer.pop_back();
            visited[i] = false;
        }
    }
}