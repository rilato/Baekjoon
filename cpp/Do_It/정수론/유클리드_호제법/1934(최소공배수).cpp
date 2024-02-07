#include <iostream>

using namespace std;

int GCD(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        int a, b, result;

        cin >> a >> b;

        result = a * b / GCD(a, b);

        cout << result << '\n';
    }

    return 0;
}

int GCD(int a, int b) {
    if (b == 0)
        return a;

    else
        return GCD(b, a % b);
}