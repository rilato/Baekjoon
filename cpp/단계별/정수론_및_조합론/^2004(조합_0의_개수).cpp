// nCm = n! / k! * (n-k)! �� �̿��Ѵ�.

// ���丮�� 0�� ������ ���������,
// ������ ���� ������ �������� �����ϹǷ� 5�� ������ ���� �ȵȴ�.
// ������ �� 2�� ����� �� ���� ����� �� �ֱ� �����̴�.
// ���� 5�� ����� 2�� ��� �� ���� ���� �����Ѵ�.


// Ʋ�� Ǯ��
// int ��� long long�� ����ϵ��� �Ѵ�.
// 5�� ����� �ƴ� 2�� ����� ����ؾ� �Ѵ�.

#include <iostream>

using namespace std;

void countZero(int n, int m);

int main()
{
    int n, m;

    cin >> n >> m;

    countZero(n, m);
}

void countZero(int n, int m) {
    int numerator = 0;
    int denominator1 = 0;
    int denominator2 = 0;

    for (int i = 5; i <= n; i *= 5)
        numerator += n / i;

    for (int i = 5; i <= m; i *= 5)
        denominator1 += m / i;

    for (int i = 5; i <= (n - m); i *= 5)
        denominator2 += (n - m) / i;

    cout << numerator - denominator1 - denominator2;
}



// ���� Ǯ��

#include <iostream>

using namespace std;

long long countZero(int n, int m, int k);

int main()
{
    int n, m, two, five;

    cin >> n >> m;

    two = countZero(n, m, 2);
    five = countZero(n, m, 5);

    cout << ((two < five) ? two : five);
}

long long countZero(int n, int m, int k) {
    long long numerator = 0;
    long long denominator1 = 0;
    long long denominator2 = 0;

    for (long long i = k; i <= n; i *= k)
        numerator += n / i;

    for (long long i = k; i <= m; i *= k)
        denominator1 += m / i;

    for (long long i = k; i <= (n - m); i *= k)
        denominator2 += (n - m) / i;

    return numerator - denominator1 - denominator2;
}