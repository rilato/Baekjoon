#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    cout << a * 56 + b * 24 + c * 14 + d * 6;

    return 0;
}