#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long Min, Max;
long A[10000001];
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Min >> Max;

    // ������ 10^14 �����̱� ������ 10^7������ �ݺ�
    for (int i = 2; i < 10000001; i++) {
        A[i] = i;
    }

    for (int i = 2; i <= sqrt(10000001); i++) { // �����ٱ����� ����
        // �Ҽ��� �ƴϸ� skip
        if (A[i] == 0) {
            continue;
        }

        // �Ҽ��̸� �Ҽ��� ���ΰ� ��� �����
        for (int j = i + i; j < 10000001; j += i) {
            A[j] = 0;
        }
    }

    for (int i = 2; i < 10000001; i++) {
        if (A[i] != 0) {
            // A[i]�� ���� �Ҽ�
            long temp = A[i];

            // ���� �Ҽ�(A[i])�� �������� Max���� ���� �� ����������
            // A[i]�� temp�� ������ long�� ������ �Ѿ �� �־� �������� ���ϱ⸦ �Ѱ� ������� �ٲپ� ó��
            while ((double)A[i] <= (double)Max / (double)temp) {
                if ((double)A[i] >= (double)Min / (double)temp) {
                    cnt++;
                }

                // temp�� A[i]�� N�������� �����Ͽ� �ֱ�
                temp *= A[i];
            }
        }
    }

    cout << cnt;
}