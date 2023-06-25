#include <iostream>

using namespace std;

bool arr[20] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, num;
    string S;

    cin >> M;

    while (M--) {
        cin >> S;

        if (S == "add") {
            cin >> num;
            arr[num - 1] = true;
        }
        if (S == "remove") {
            cin >> num;
            arr[num - 1] = false;
        }
        if (S == "check") {
            cin >> num;

            if (arr[num - 1])
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        if (S == "toggle") {
            cin >> num;

            if (arr[num - 1])
                arr[num - 1] = false;
            else
                arr[num - 1] = true;
        }
        if (S == "all") {
            for (int i = 0; i < 20; i++) {
                arr[i] = true;
            }
        }
        if (S == "empty") {
            for (int i = 0; i < 20; i++) {
                arr[i] = false;
            }
        }
    }
}