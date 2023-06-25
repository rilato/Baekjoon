#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int snack, n, money;
    int product;

    cin >> snack >> n >> money;

    product = snack * n;

    if (product > money)
        cout << product - money;
    else
        cout << 0;
}