#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr1[4] = { 0, };
    int arr2[2] = { 0, };
    int ans = 0;

    for (int i = 0; i < 4; i++) {
        cin >> arr1[i];

        ans += arr1[i];
    }

    sort(arr1, arr1 + 4);

    ans -= arr1[0];

    for (int i = 0; i < 2; i++) {
        cin >> arr2[i];

        ans += arr2[i];
    }

    sort(arr2, arr2 + 2);

    ans -= arr2[0];

    cout << ans;
}