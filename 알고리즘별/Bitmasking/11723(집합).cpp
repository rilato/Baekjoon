#include <iostream>

using namespace std;

int M, num;
string input;
bool arr[21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;

    while (M--) {
        cin >> input;

        if (input == "add") {
            cin >> num;

            arr[num] = true;
        }
        if (input == "remove") {
            cin >> num;

            arr[num] = false;
        }
        if (input == "check") {
            cin >> num;

            if (arr[num]) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        if (input == "toggle") {
            cin >> num;

            if (arr[num]) {
                arr[num] = false;
            }
            else {
                arr[num] = true;
            }
        }
        if (input == "all") {
            for (int i = 1; i <= 20; i++) {
                arr[i] = true;
            }
        }
        if (input == "empty") {
            for (int i = 1; i <= 20; i++) {
                arr[i] = false;
            }
        }
    }

    return 0;
}