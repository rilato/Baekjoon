// C����� scanf�� ����ϸ� ���� �ذ� �����ϴ�.
// 16������ ��Ÿ���� "%x"�� Ȱ���Ѵ�.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {
    int num;

    scanf("%x", &num);

    printf("%d", num);

    return 0;
}


// C��� ��Ÿ���� �ƴϴ��� Ǯ�̰� �����ϴ�.
// cin >> hex >> ����; ������ Ȱ���Ѵ�.

#include <iostream>
using namespace std;

int main(void) {
    int a;

    cin >> hex >> a;

    cout << a;
}