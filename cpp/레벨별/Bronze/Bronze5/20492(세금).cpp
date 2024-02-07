#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int money, money2;

    cin >> money;

    money2 = money - (int)(money * 0.2 * 0.22);
    money *= 0.78;

    cout << money << ' ' << money2;
}