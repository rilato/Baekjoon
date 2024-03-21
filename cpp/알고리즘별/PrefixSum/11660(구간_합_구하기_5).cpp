#include <iostream>
#include <vector>

using namespace std;

int N, M, num, r1, r2, c1, c2;
vector <vector <int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(N + 1, vector <int>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> num;

            v[i][j] = num + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> r1 >> c1 >> r2 >> c2;

        cout << v[r2][c2] - v[r2][c1 - 1] - v[r1 - 1][c2] + v[r1 - 1][c1 - 1] << '\n';
    }

    return 0;
}
