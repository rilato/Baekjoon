#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n1, n2;

    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> n1 >> n2;

        cout << "Case " << i << ": " << n1 + n2 << '\n';
    }

    return 0;
}