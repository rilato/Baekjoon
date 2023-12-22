#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, j, h;
    int s, b;   // small, big
    int cnt = 1;

    cin >> N >> j >> h;

    if (j > h) {
        s = h;
        b = j;
    }
    else {
        s = j;
        b = h;
    }

    while (1) {
        if (b - s == 1 && b % 2 == 0) {
            break;
        }

        if (N == 0) {
            cout << "-1";
            return 0;
        }

        if (b % 2 == 1) {
            b = (b + 1) / 2;
        }
        else if (b % 2 == 0) {
            b /= 2;
        }
        if (s % 2 == 1) {
            s = (s + 1) / 2;
        }
        else if (s % 2 == 0) {
            s /= 2;
        }

        N /= 2;

        cnt++;
    }

    cout << cnt;

    return 0;
}
