#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long gcd(long a, long b);
vector<long> Excute(long a, long b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long a, b, c;

    cin >> a >> b >> c;

    long tgcd = gcd(a, b);

    if (c % tgcd != 0) {
        cout << -1 << "\n";
    }

    else {
        int mok = (int)(c / tgcd);
        vector<long> ret = Excute(a, b);    // ������ (b)�� 0�� �� ������ ��� �Լ� ȣ���ϴ� ��Ŭ���� ȣ���� �Լ� ȣ��

        cout << ret[0] * mok << " " << ret[1] * mok;    // �� ������� (c / �ִ�����) ���� ���Ͽ� �ְ� �ش� ���� ����ϱ�
    }
}

// ��Ŭ���� ȣ���� �Լ� ����
vector<long> Excute(long a, long b) {
    vector<long> ret(2);

    if (b == 0) {
        ret[0] = 1;
        ret[1] = 0;

        return ret;
    }

    long q = a / b;
    vector<long> v = Excute(b, a % b); 	// ��� ���·� ȣ���� ����

    // X = Y' , Y = X' - (Y' * ��)�� ����ϴ� ���� ���� ����
    ret[0] = v[1];  		// ������ �ö���鼭 X, Y ���� ����ϴ� ����
    ret[1] = v[0] - v[1] * q;

    return ret;
}

long gcd(long a, long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}