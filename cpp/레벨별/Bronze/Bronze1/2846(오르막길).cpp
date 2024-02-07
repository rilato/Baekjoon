#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int arr[1000] = { 0, };
    int gap = 0;
    int ans = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            gap += arr[i + 1] - arr[i];
            ans = max(gap, ans);
        }

        else {
            gap = 0;
        }
    }

    cout << ans;
}