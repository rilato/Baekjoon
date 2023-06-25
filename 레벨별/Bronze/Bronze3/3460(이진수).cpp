#include <iostream>  

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, n;

    cin >> T;

    while (T--) {
        int digit = 0;

        cin >> n;

        while (n > 0) {
            if (n % 2 == 1) {
                cout << digit << " ";
            }

            n /= 2;

            digit++;
        }
    }

    return 0;
}