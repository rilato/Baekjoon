#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[6] = { 1, 1, 2, 2, 2, 8 };
    int num;

    for (int i = 0; i < 6; i++) {
        cin >> num;
        cout << arr[i] - num << ' ';
    }
}