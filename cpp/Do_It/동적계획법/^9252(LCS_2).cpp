#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string A, B;
int DP[1001][1001]; // ������ ��ȭ�� ���̺�
vector<char> Path;  // LCS ���� ����

void getText(int r, int c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    for (int i = 1; i <= A.size(); i++) {
        for (int j = 1; j <= B.size(); j++) {
            // ���� ���ڿ��� ��� ���� �밢�� �� + 1
            if (A[i - 1] == B[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            // �ٸ� ���ڿ��� ��� ���ʰ� ���� �� �� ū ��
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << DP[A.size()][B.size()] << '\n';

    getText(A.size(), B.size());

    // Path�� ����� ���� �Ųٷ� ���
    for (int i = Path.size() - 1; i >= 0; i--) {
        cout << Path[i];
    }

    return 0;
}

// LCS ��� �Լ�, ��� ���·� ����
void getText(int r, int c) {
    if (r == 0 || c == 0) {
        return;
    }

    // A[row]�� B[column]�� ������ LCS�� ����ϰ� ���� ���� �̵�
    if (A[r - 1] == B[c - 1]) {
        Path.push_back(A[r - 1]);
        getText(r - 1, c - 1);
    }
    // A[row]�� B[column]�� �ٸ��� ���ʰ� ���� �� ū ���� �̵�
    else {
        if (DP[r - 1][c] > DP[r][c - 1]) {
            getText(r - 1, c);
        }
        else {
            getText(r, c - 1);
        }
    }
}