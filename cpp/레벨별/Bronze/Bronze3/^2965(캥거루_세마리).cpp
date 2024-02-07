// 최대 이동 횟수는
// 1. 가장 큰 수 - 중간 수 - 1
// 2. 중간 수 - 가장 작은 수 - 1

// 1, 2번 중 더 큰 수만큼 점프가 가능합니다.

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;

    cin >> A >> B >> C;

    if (C - B > B - A)
        cout << C - B - 1;

    else
        cout << B - A - 1;

    return 0;
}