// 예외 처리에 주의한다.
// 또한 예외 처리시, 프로그램 종료할 때 return 0;을 꼭 써준다.

#include <iostream>
#include <cmath>

using namespace std;

double line(double x1, double x2, double y1, double y2);

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double x1, y1, x2, y2, x3, y3;
    double line1, line2, line3, sum1, sum2, sum3, my_max, my_min;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // 점 세 개가 한 점 위에 있는 경우
    // abs(y2 - y1)/abs(x2 - x1) == abs(y3 - y2)/abs(x3 - x2)
    // 분모가 0이면 안되니까 양변에 분모 값을 곱함
    if (abs(y2 - y1) * abs(x3 - x2) == abs(y3 - y2) * abs(x2 - x1)) {
        cout << -1;
        // 프로그램이 종료되어야 하므로 return0;
        return 0;
    }

    // D 점을 구하지 않고도 나머지 세 점을 이용해서 평행사변형의 둘레를 찾을 수 있다.
    line1 = line(x1, x2, y1, y2);
    line2 = line(x1, x3, y1, y3);
    line3 = line(x2, x3, y2, y3);

    sum1 = 2 * (line1 + line2);
    sum2 = 2 * (line1 + line3);
    sum3 = 2 * (line2 + line3);

    // cmath의 내장함수 max,min함수는 인자를 두 개 밖에 받지 못하므로 나눠서 계산한다.
    my_max = max(sum1, max(sum2, sum3));
    my_min = min(sum1, min(sum2, sum3));

    cout << fixed;
    cout.precision(16);

    cout << my_max - my_min;
}

double line(double x1, double x2, double y1, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}