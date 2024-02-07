#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    long long arr[16] = { 0, };

    cin >> n;

    // 앞 값과 뒷 값의 차가 1, 2, 4, 8 ...
    arr[0] = 2;

    for (int i = 1; i < 16; i++) {
        arr[i] = arr[i - 1] + pow(2, i - 1);
    }

    cout << arr[n] * arr[n];

    return 0;
}