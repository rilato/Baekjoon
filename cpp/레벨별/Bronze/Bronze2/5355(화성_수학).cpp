#include <iostream>

using namespace std;

int T;
double num;
char c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> num;

        while (1) {
            cin.get(c);

            if (c == '\n') {
                break;
            }
            if (c == '@') {
                num *= 3;
            }

            if (c == '%') {
                num += 5;
            }

            if (c == '#') {
                num -= 7;
            }

        }

        cout << fixed;
        cout.precision(2);
        cout << num << "\n";
    }

    return 0;
}
