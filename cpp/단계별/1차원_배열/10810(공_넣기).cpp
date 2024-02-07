#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    vector <int> v(N);

    for (int i = 0; i < M; i++) {
        int start, end, x;

        cin >> start >> end >> x;

        for (int j = start - 1; j < end; j++) {
            v[j] = x;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }

    return 0;
}