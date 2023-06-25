#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    // 40까지의 수를 다뤄야 하는데, 0 ~ 40까지의 인덱스를 가지므로 41로 설정한다.
    long long fib[41] = { 0, };

    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i < 41; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    cin >> N;

    cout << fib[N] << " " << N - 2;
}