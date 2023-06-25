#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, rem;
    int ans = 0;
    int arr[10] = { 0, };

    cin >> N;

    while (1) {
        if (!N)
            break;
        else {
            rem = N % 10;
            arr[rem]++;
            N /= 10;
        }
    }

    // /2를 했을 때 원하는 결과를 만들기 위해 +1을 인위적으로 해준다.
    arr[6] = (arr[6] + 1 + arr[9]) / 2;

    for (int i = 0; i < 9; i++) {
        ans = max(ans, arr[i]);
    }

    cout << ans;
}