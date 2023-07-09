// long type�� �ƴ� long long type���� �����Ѵ�.
// a�� b�� �ִ������� ���̸�ŭ 1�� ��Ÿ�� ���� ���̴�.

#include <iostream>

using namespace std;

long long GCD(long long a, long long b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;

    cin >> a >> b;

    long long result = GCD(a, b);

    while (result--) {
        cout << 1;
    }

    return 0;
}

long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}