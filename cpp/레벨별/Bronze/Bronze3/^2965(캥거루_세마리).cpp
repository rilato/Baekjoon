// �ִ� �̵� Ƚ����
// 1. ���� ū �� - �߰� �� - 1
// 2. �߰� �� - ���� ���� �� - 1

// 1, 2�� �� �� ū ����ŭ ������ �����մϴ�.

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;

    cin >> A >> B >> C;

    if (C - B > B - A)
        cout << C - B - 1;

    else
        cout << B - A - 1;

    return 0;
}