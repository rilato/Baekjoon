// https://torbjorn.tistory.com/247 ����

// 2�� ����� 5�� ����� ���� 10�� ����� �̷��, 10�� ����� 10�� �̷��.

// 5�� ����� ������ ����.
// 5�� ����� 2�� ����� ���� 10�� ����� �̷�� �ȴ�.
// 2�� ����� ���� �����Ƿ�, 5�� ����� ������ ��� �ű�� �ϳ��� �ٿ��ָ� 10�� ����� �Ǵ� ���̴�.

// ���� ���� : 5�� ��� ��, 25�� 125�� ���� 5�� 2��, 5�� 3�� ���� �� �����Ƿ�, �̿� �����Ͽ� Ǯ���Ѵ�.


// Ʋ�� Ǯ��
// 25�� 125 ���� ���� ������� �ʾҴ�.

// 2�� ����� 5�� ����� ���� 10�� ����� �̷��, 10�� ����� 10�� �̷��.

#include <iostream>

using namespace std;

void countZero(int num);

int main()
{
    int num;

    cin >> num;

    countZero(num);
}

void countZero(int num) {
    int count = 0;

    while (1) {
        if (!num)
            break;

        // 5�� ����� ������ ����.
        // 5�� ����� 2�� ����� ���� 10�� ����� �̷�� �ȴ�.
        // 2�� ����� ���� �����Ƿ�, 5�� ����� ������ ��� �ű�� �ϳ��� �ٿ��ָ� 10�� ����� �Ǵ� ���̴�.
        if (!(num % 5))
            ++count;

        num--;
    }

    cout << count;
}


// ���� Ǯ��

#include <iostream>

using namespace std;

void countZero(int num);

int main()
{
    int num;

    cin >> num;

    countZero(num);
}

void countZero(int num) {
    int count = 0;

    for (int i = 5; i <= num; i *= 5) {
        count += num / i;
    }

    cout << count;
}