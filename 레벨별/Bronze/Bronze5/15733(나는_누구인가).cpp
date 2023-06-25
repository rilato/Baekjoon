#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int L;

    cin >> L;

    if (L % 5 == 0)
        cout << L / 5;
    else
        cout << L / 5 + 1;
}