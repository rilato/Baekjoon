#include <iostream>

using namespace std;

int armor, ignore;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> armor >> ignore;

    /**
    처음 코드 : double shield = (double)armor * (1 - (double)ignore / 100);

    부동소수점 표현의 한계로, 소수를 정확하게 나타내지 못하는 특징 탓에
    500 80 으로 만들어진 100이 실제로는 99.999999999999972의 값을 갖더라구요.
    소숫점을 크게 잡지 않고 출력하면 반올림이 돼서 출력되기에 100으로 보였던 겁니다.
    */

    double shield = (double)armor * (100 - ignore) / 100;

    if (shield >= 100) {
        cout << 0;
    }
    else {
        cout << 1;
    }

    return 0;
}