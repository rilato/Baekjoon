#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char a[10];

    cin.getline(a, 10);

    if ((a[0] - '0') + (a[4] - '0') == (a[8] - '0'))
        cout << "YES" << '\n';

    else
        cout << "NO" << '\n';

    return 0;
}