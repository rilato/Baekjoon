#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n1, n2;

    while (1) {
        cin >> n1 >> n2;

        if (!n1 && !n2)
            break;

        cout << n1 + n2 << '\n';
    }
}