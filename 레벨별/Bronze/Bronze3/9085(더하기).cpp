#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, num;
    int arr[10] = { 0, };

    cin >> T;

    while (T--) {
        int sum = 0;

        cin >> num;

        for (int i = 0; i < num; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < num; i++) {
            sum += arr[i];
        }

        cout << sum << '\n';
    }
}