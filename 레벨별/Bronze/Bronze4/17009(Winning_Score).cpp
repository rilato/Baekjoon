#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int a = 0, b = 0;

    for (int i = 3; i > 0; i--) {
        cin >> n;
        a += n * i;
    }

    for (int i = 3; i > 0; i--) {
        cin >> n;
        b += n * i;
    }

    if (a > b)
        cout << 'A';

    else if (a < b)
        cout << 'B';

    else
        cout << 'T';

    return 0;
}