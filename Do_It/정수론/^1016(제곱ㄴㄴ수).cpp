// �� ������ �Ҽ��� ���� �� ����ϴ� �����佺�׳׽��� ü�� ������ ����Ѵ�.
// 2���� �����ؼ� min ~ max ���̿� �ִ� �������� üũ�ؾ� �ϴµ�,
// �̶� �ִ� 10 ^ 12���� �Է��� ������ ������ �������� �״�� arr�� index�� ����ϰ� �Ǹ� �޸𸮰� �������� ���Ѵ�.
// (arr[10 ^ 12]�� �����ؾ� �ϱ� �����̴�)

// ���� �������� �ٸ� �������� min�� max�� ���̰� �ִ� 10 ^ 6�̶�� �߱� ������,
// check(Max - Min + 1) (�ִ� 10 ^ 6�� ũ��)¥���� �����Ͽ�(������ - min)���� index�� ����ߴ�.

#include <iostream>
#include <vector>

using namespace std;

long long Min, Max;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Min >> Max;

    // �ִ񰪰� �ּڰ��� ���̸�ŭ �迭 ����
    vector <bool> check(Max - Min + 1);

    // 1�� �����ϰ�, 2�� �������� 4���� Max���� �۰ų� ���� ������ �ݺ�
    for (long long i = 2; i * i <= Max; i++) {
        long long pow = i * i;
        long long start_index = Min / pow;  // Min������ �������� ������ �����佺�׳׽��� ü���� ������ j�� ���� ���� ����

        // Min���� ū ���������� ���۵ǵ��� �ϴ� �۾�
        if (Min % pow != 0) {
            // �������� ������ 1�� �����־�� Min���� ū ���������� ���۵�
            // ex) Min = 5, pow = 4 => �������� �����Ƿ�, start_index�� 1�� �ƴ�, 2
            start_index++;
        }

        // �������� ����� true�� ����
        for (long long j = start_index; pow * j <= Max; j++) {
            // j * pow�� �������� ���
            check[(int)((j * pow) - Min)] = true;
        }
    }

    int cnt = 0;

    for (int i = 0; i <= Max - Min; i++) {
        if (!check[i]) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}