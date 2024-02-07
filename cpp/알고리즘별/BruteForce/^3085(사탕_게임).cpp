// 110��° �ٿ��� cntRow�� �ؾ��ϴµ� cntCol �Լ��� �߸� ��� Ʋ�ȴ�..

#include <iostream>
#include <vector>

using namespace std;

int N;
int maximum = 0;
vector <vector <char>> v;

void cntRow(int i);
void cntCol(int j);
void swap1(int i, int j);
void swap2(int i, int j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N, vector <char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    // �ϴ� ��ü Ž�� (��)
    for (int i = 0; i < N; i++) {
        int temp = 1;

        for (int j = 0; j < N - 1; j++) {
            // ���� �����ִ� ���ڿ� �� ���� ���ڰ� �ٸ� ���
            if (v[i][j] != v[i][j + 1]) {
                if (temp > maximum) {
                    maximum = temp;
                }

                temp = 0;
            }
            // ���� �����ִ� ���ڿ� �� ���� ���ڰ� ���� ���
            else {
                temp++;

                // ���������� �ôٸ�, maximum Ȯ�� �� ����
                if (j == N - 2 && temp > maximum) {
                    maximum = temp;
                }
            }
        }
    }

    // �ϴ� ��ü Ž�� (��)
    for (int j = 0; j < N; j++) {
        int temp = 1;

        for (int i = 0; i < N - 1; i++) {
            // ���� �����ִ� ���ڿ� �� ���� ���ڰ� �ٸ� ���
            if (v[i][j] != v[i + 1][j]) {
                if (temp > maximum) {
                    maximum = temp;
                }

                temp = 0;
            }
            // ���� �����ִ� ���ڿ� �� ���� ���ڰ� ���� ���
            else {
                temp++;

                // ���������� �ôٸ�, maximum Ȯ�� �� ����
                if (i == N - 2 && temp > maximum) {
                    maximum = temp;
                }
            }
        }
    }

    // ���� �� ������ ����
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (v[i][j] != v[i][j + 1]) {
                swap1(i, j);

                // ���� �࿡�� maximum ���� �ľ�
                cntRow(i);
                // �ٲ� ������ maximum ���� �ľ�
                cntCol(j);
                // �ٲ� ������ maximum ���� �ľ�
                cntCol(j + 1);

                // ������� ��������
                swap1(i, j);
            }
        }
    }

    // ���� �� ������ ����
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N - 1; i++) {
            if (v[i][j] != v[i + 1][j]) {
                swap2(i, j);

                // �ٲ� �࿡�� maximum ���� �ľ�
                cntRow(i);
                // �ٲ� �࿡�� maximum ���� �ľ�
                cntRow(i + 1);
                // ���� ������ maximum ���� �ľ�
                cntCol(j);

                // ������� ��������
                swap2(i, j);
            }
        }
    }

    cout << maximum;

    return 0;
}

// ���� �ೢ�� Ž��
void cntRow(int row) {
    int temp = 1;

    for (int j = 0; j < N - 1; j++) {
        // ���� �����ִ� ���ڿ� �� ���� ���ڰ� �ٸ� ���
        if (v[row][j] != v[row][j + 1]) {
            if (temp > maximum) {
                maximum = temp;
            }

            temp = 1;
        }
        // ���� �����ִ� ���ڿ� �� ���� ���ڰ� ���� ���
        else {
            temp++;

            // ���������� �ôٸ�, maximum Ȯ�� �� ����
            if (j == N - 2 && temp > maximum) {
                maximum = temp;
            }
        }
    }
}

// ���� ������ Ž��
void cntCol(int col) {
    int temp = 1;

    for (int i = 0; i < N - 1; i++) {
        // ���� �����ִ� ���ڿ� �� ���� ���ڰ� �ٸ� ���
        if (v[i][col] != v[i + 1][col]) {
            if (temp > maximum) {
                maximum = temp;
            }

            temp = 1;
        }
        // ���� �����ִ� ���ڿ� �� ���� ���ڰ� ���� ���
        else {
            temp++;

            // ���������� �ôٸ�, maximum Ȯ�� �� ����
            if (i == N - 2 && temp > maximum) {
                maximum = temp;
            }
        }
    }
}

void swap1(int i, int j) {
    int tmp = v[i][j];
    v[i][j] = v[i][j + 1];
    v[i][j + 1] = tmp;
}

void swap2(int i, int j) {
    int tmp = v[i][j];
    v[i][j] = v[i + 1][j];
    v[i + 1][j] = tmp;
}