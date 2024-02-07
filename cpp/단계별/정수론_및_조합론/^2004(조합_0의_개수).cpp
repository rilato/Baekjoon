// nCm = n! / k! * (n-k)! 을 이용한다.

// 팩토리얼 0의 개수와 비슷하지만,
// 조합을 구할 때에는 나눗셈을 포함하므로 5의 개수만 세면 안된다.
// 나눴을 때 2의 배수가 더 많이 사라질 수 있기 때문이다.
// 따라서 5의 배수와 2의 배수 중 작은 것을 선택한다.


// 틀린 풀이
// int 대신 long long을 사용하도록 한다.
// 5의 배수가 아닌 2의 배수도 고려해야 한다.

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



// 맞은 풀이

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