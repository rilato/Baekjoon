// Ʋ�� Ǯ��
// �� ��ȯ �������� ������ �߻����� ���ɼ��� ũ��.

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int D, H, W;
    double x, num1, num2;

    cin >> D >> H >> W;

    x = sqrt(D * D / (H * H + W * W));
    num1 = floor(x * H);
    num2 = floor(x * W);

    cout << num1 << ' ' << num2;
}


// ���� Ǯ��

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int diagonal, heightRatio, widthRatio;

    cin >> diagonal >> heightRatio >> widthRatio;

    double x = sqrt((double)(diagonal * diagonal) / (heightRatio * heightRatio + widthRatio * widthRatio));
    int height = floor(heightRatio * x);
    int width = floor(widthRatio * x);

    cout << height << " " << width << "\n";
}