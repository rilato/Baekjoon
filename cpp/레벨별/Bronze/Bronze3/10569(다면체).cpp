#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, v, e;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> v >> e;

        cout << 2 - v + e << '\n';
    }

    return 0;
}