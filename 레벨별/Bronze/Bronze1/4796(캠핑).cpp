#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i = 1;
    int l, p, v;
    int res = 0;

    while (1) {
        cin >> l >> p >> v;

        if (!l && !p && !v)
            break;

        res = min(v % p, l) + (v / p) * l;

        cout << "Case " << i++ << ": " << res << "\n";
    }

    return 0;
}