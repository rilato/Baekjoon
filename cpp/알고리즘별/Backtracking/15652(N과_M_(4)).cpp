#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> v;

void Backtracking(int num, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    Backtracking(1, 0);

    return 0;
}

void Backtracking(int num, int depth) {
    if (depth == M) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }

        cout << '\n';

        return;
    }

    for (int i = num; i <= N; i++) {
        v.push_back(i);
        Backtracking(i, depth + 1);
        v.pop_back();
    }
}