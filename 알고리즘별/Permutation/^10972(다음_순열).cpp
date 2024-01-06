// https://softworking.tistory.com/230
// https://pirateturtle.tistory.com/237

#include <iostream>
#include <algorithm>

using namespace std;

// �Էµ� ����
int num[10000] = { 0, };
int N;
// flag : ������ �������� Ȯ���� ���� ����
int flag = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // ���� �Է�
    for (int n = 0; n < N; n++) {
        cin >> num[n];
    }

    // �Էµ� ������ ���������� �˻�
    for (int i = N - 1; i > 0; i--) {
        // ���� ����(����) < ������ ����
        if (num[i - 1] < num[i]) {
            // index : ��ȯ�� ������ �ε��� (i�� �ּ��� index�� ã�� ����)
            int index = i;
            // ���� ���Һ��� �����ʿ� �����鼭 
            for (int j = N - 1; j >= i; j--) {
                // ���� ���Һ��� ũ�鼭 + ���� ���� ����
                if (num[i - 1] < num[j] && num[j] < num[index]) {
                    index = j;
                }
            }

            // ��ȯ �۾�
            int temp = num[index];
            num[index] = num[i - 1];
            num[i - 1] = temp;

            // ���� ���� ���� ������������ ����
            sort(num + i, num + N);

            // ������ ������ �ƴ϶�� ��ȣ
            flag = 1;
            break;
        }
    }

    // ������ ������ ���
    if (flag == 0) {
        cout << -1;
    }
    // ������ ������ �ƴ� ���
    else {
        for (int n = 0; n < N; n++) {
            cout << num[n] << " ";
        }
    }

    return 0;
}