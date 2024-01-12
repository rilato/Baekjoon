#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> v;

void Backtracking(int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(M);

    Backtracking(0);

    return 0;
}

void Backtracking(int depth) {
    if (depth == M) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }

        cout << '\n';

        return;
    }

    for (int i = 1; i <= N; i++) {
        v[depth] = i;
        Backtracking(depth + 1);
    }
}