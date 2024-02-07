// long type이 아닌 long long type으로 선언한다.
// a와 b의 최대공약수의 길이만큼 1로 나타낸 것이 답이다.

#include <iostream>

using namespace std;

long long GCD(long long a, long long b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;

    cin >> a >> b;

    long long result = GCD(a, b);

    while (result--) {
        cout << 1;
    }

    return 0;
}

long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}