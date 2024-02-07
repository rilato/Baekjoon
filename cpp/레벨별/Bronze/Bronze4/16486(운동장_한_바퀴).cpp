#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d1, d2;
    double pi = 3.141592;

    cin >> d1 >> d2;

    cout << fixed;
    cout.precision(6);

    cout << 2 * (d1 + d2 * pi);
}