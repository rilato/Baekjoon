#include <iostream>

using namespace std;

long long arr[46];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;

    cin >> K;

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= K; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[K - 1] << " " << arr[K];
}