// 소수점 아래 두 자리까지 표시하는 방법을 확인한다.

#include <iostream>

using namespace std;

int main() {
    int T;
    double A, B, C, D, E;
    double a = 350.34;
    double b = 230.90;
    double c = 190.55;
    double d = 125.30;
    double e = 180.90;
    double sum = 0;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> A >> B >> C >> D >> E;

        sum = a * A + b * B + c * C + d * D + e * E;

        printf("$%.2f\n", sum);
    }
}