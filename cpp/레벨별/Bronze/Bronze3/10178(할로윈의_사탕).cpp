#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, c, v;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> c >> v;

        cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s).\n";
    }

    return 0;
}