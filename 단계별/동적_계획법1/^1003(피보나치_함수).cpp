// �ð� �ʰ��� �� Ǯ��
// �������� �־��� �Լ��� �״�� ����Ͽ����� �ð� �ʰ��� �߻��ߴ�.
// ����� ���·� �̷�����־ ���� Ŀ������ ���� ���� �ð��� �ɸ���.

#include <iostream>
#include <vector>

using namespace std;

int arr[2] = { 0, };

int fibonacci(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        fibonacci(num);

        cout << arr[0] << ' ' << arr[1] << '\n';

        arr[0] = 0;
        arr[1] = 0;
    }
}

int fibonacci(int n) {
    if (n == 0) {
        ++arr[0];
        return 0;
    }
    else if (n == 1) {
        ++arr[1];
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}


// ���� Ǯ��
// 0 1�� ȣ�� Ƚ���� ����ϴ� ���� ������ ���踦 ã�Ƴ���.
// n == 0 �� �� 1, 0�� ���������
// n == 1 ���ʹ� 0�� 1 ��� �Ǻ���ġ ������ �̷�����.

#include <iostream>

using namespace std;

int fibArr[41] = { 0, 1, };

int fibonacci(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;

        if (num == 0)
            cout << "1 0" << '\n';

        else
            cout << fibonacci(num - 1) << ' ' << fibonacci(num) << '\n';
    }
}

int fibonacci(int n) {
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    if (n >= 2) {
        for (int i = 2; i <= n; i++) {
            fibArr[i] = fibArr[i - 1] + fibArr[i - 2];
        }

        return fibArr[n];
    }
}