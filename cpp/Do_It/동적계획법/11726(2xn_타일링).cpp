#include <iostream>

using namespace std;

int N;
long long arr[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr[1] = 9;

    for (int i = 2; i <= N; i++) {
        arr[i] = (arr[i - 1] * 2 - (N - 1)) % 1000000000;
    }

    cout << arr[N] % 1000000000;

    return 0;
}