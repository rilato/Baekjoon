#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    int arr[5] = { 0, };

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        if (!x || !y)
            arr[0]++;
        else if (x > 0 && y > 0)
            arr[1]++;
        else if (x < 0 && y > 0)
            arr[2]++;
        else if (x < 0 && y < 0)
            arr[3]++;
        else
            arr[4]++;
    }

    for (int i = 1; i <= 4; i++) {
        cout << "Q" << i << ": " << arr[i] << '\n';
    }

    cout << "AXIS: " << arr[0];

    return 0;
}