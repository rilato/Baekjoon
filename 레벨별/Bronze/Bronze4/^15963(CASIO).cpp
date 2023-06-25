// 10자리 정수이므로 long long을 쓴다.

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m;

    cin >> n >> m;

    if (n == m)
        cout << 1;
    else
        cout << 0;
}