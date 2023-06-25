// ���� ó���� �����Ѵ�.
// ���� ���� ó����, ���α׷� ������ �� return 0;�� �� ���ش�.

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

    // �� �� ���� �� �� ���� �ִ� ���
    // abs(y2 - y1)/abs(x2 - x1) == abs(y3 - y2)/abs(x3 - x2)
    // �и� 0�̸� �ȵǴϱ� �纯�� �и� ���� ����
    if (abs(y2 - y1) * abs(x3 - x2) == abs(y3 - y2) * abs(x2 - x1)) {
        cout << -1;
        // ���α׷��� ����Ǿ�� �ϹǷ� return0;
        return 0;
    }

    // D ���� ������ �ʰ� ������ �� ���� �̿��ؼ� ����纯���� �ѷ��� ã�� �� �ִ�.
    line1 = line(x1, x2, y1, y2);
    line2 = line(x1, x3, y1, y3);
    line3 = line(x2, x3, y2, y3);

    sum1 = 2 * (line1 + line2);
    sum2 = 2 * (line1 + line3);
    sum3 = 2 * (line2 + line3);

    // cmath�� �����Լ� max,min�Լ��� ���ڸ� �� �� �ۿ� ���� ���ϹǷ� ������ ����Ѵ�.
    my_max = max(sum1, max(sum2, sum3));
    my_min = min(sum1, min(sum2, sum3));

    cout << fixed;
    cout.precision(16);

    cout << my_max - my_min;
}

double line(double x1, double x2, double y1, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}