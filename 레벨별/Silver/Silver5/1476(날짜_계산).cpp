#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int E, S, M;
    int e = 1;
    int s = 1;
    int m = 1;
    int year = 1;

    cin >> E >> S >> M;

    while (1) {
        e = year % 15;
        s = year % 28;
        m = year % 19;

        if (!e)
            e += 15;
        if (!s)
            s += 28;
        if (!m)
            m += 19;

        if (e == E && s == S && m == M)
            break;

        year++;
    }

    cout << year;
}