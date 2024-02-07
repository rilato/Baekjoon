// https://mygumi.tistory.com/284
// https://donggoolosori.github.io/2020/09/22/boj-1074-Z/

// 재귀함수의 구현 방법이 익숙치 않아 연습이 필요하다..

#include <iostream>

using namespace std;

int n, r, c;
int ans;

void Z(int y, int x, int size);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> c;

    // 1 << n은 비트 연산
    // 2의 n승을 표현하기 위함
    // 000001에서 n이 1이면 1비트만큼 왼쪽으로 이동 -> 000010 = 2
    // 000001에서 n이 2이면 2비트만큼 왼쪽으로 이동 -> 000100 = 4
    Z(0, 0, (1 << n));

    return 0;
}

void Z(int y, int x, int size) {
    if (y == r && x == c) {
        cout << ans << '\n';
        return;
    }

    // r,c가 현재 사분면에 존재한다면
    if (r < y + size && r >= y && c < x + size && c >= x) {
        // 1사분면 탐색
        Z(y, x, size / 2);
        // 2사분면 탐색
        Z(y, x + size / 2, size / 2);
        // 3사분면 탐색
        Z(y + size / 2, x, size / 2);
        // 4사분면 탐색
        Z(y + size / 2, x + size / 2, size / 2);
    }

    else {
        ans += size * size;
    }
}