// 피보나치 수열의 형태를 이루는데, 나중되면 값이 커지므로 배열을 int가 아닌 long long 형식으로 선언한다.

#include <iostream>

using namespace std;

int N;
long long arr[91];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr[1] = 1;
    arr[2] = 1;

    for (int i = 3; i <= N; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[N];

    return 0;
}