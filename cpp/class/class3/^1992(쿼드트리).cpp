// �Է��� ���ڿ��� �޴´�.
// ����Լ����� 2�� for���� �������Դٸ�, ���� Ž���ϰ��ִ� ������ ���ڴ� ��� �����Ƿ�, �ش� ���ڸ� ����Ѵ�.

#include <iostream>

using namespace std;

int N;
string arr[64];

void recursive(int x, int y, int size);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    recursive(0, 0, N);

    return 0;
}

void recursive(int x, int y, int size) {
    char temp = arr[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != temp) {
                int len = size / 2;

                cout << "(";

                recursive(x, y, len);
                recursive(x, y + len, len);
                recursive(x + len, y, len);
                recursive(x + len, y + len, len);

                cout << ")";

                return;
            }
        }
    }

    cout << temp;
}