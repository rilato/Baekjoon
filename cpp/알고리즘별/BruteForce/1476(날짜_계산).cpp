#include <iostream>

using namespace std;

int E, S, M;
int tempE, tempS, tempM;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> E >> S >> M;

    for (int i = 1; i <= 2100000000; i++) {
        // 15�� ������ �������� 0�̶��, tempE = 15�� ����
        if (i % 15 == 0) {
            tempE = 15;
        }
        else if (i % 15 != 0) {
            tempE = i % 15;
        }
        // 28�� ������ �������� 0�̶��, tempS = 28�� ����
        if (i % 28 == 0) {
            tempS = 28;
        }
        else if (i % 28 != 0) {
            tempS = i % 28;
        }
        // 19�� ������ �������� 0�̶��, tempM = 19�� ����
        if (i % 19 == 0) {
            tempM = 19;
        }
        else if (i % 19 != 0) {
            tempM = i % 19;
        }

        if (tempE == E && tempS == S && tempM == M) {
            cout << i;
            break;
        }
    }

    return 0;
}