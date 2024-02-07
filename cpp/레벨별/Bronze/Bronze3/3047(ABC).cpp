#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[3];
    string s;

    for (int i = 0; i < 3; i++)
        cin >> arr[i];

    cin >> s;

    sort(arr, arr + 3);

    for (int i = 0; i < s.length(); i++)
        cout << arr[s[i] - 'A'] << " ";

    return 0;
}