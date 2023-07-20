#include <iostream>

using namespace std;

int armor, ignore;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> armor >> ignore;

    /**
    ó�� �ڵ� : double shield = (double)armor * (1 - (double)ignore / 100);

    �ε��Ҽ��� ǥ���� �Ѱ��, �Ҽ��� ��Ȯ�ϰ� ��Ÿ���� ���ϴ� Ư¡ ſ��
    500 80 ���� ������� 100�� �����δ� 99.999999999999972�� ���� �����󱸿�.
    �Ҽ����� ũ�� ���� �ʰ� ����ϸ� �ݿø��� �ż� ��µǱ⿡ 100���� ������ �̴ϴ�.
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