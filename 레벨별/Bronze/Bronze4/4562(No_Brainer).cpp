#include <iostream>

using namespace std;

int T, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> a >> b;

        if (a < b) {
            cout << "NO BRAINS\n";
        }
        else {
            cout << "MMM BRAINS\n";
        }
    }

    return 0;
}
