#include <iostream>
#include <climits>

using namespace std;

string A, B;
int sizeGap;
int gap = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;

    // A�� ũ��� �׻� B���� �۰ų� ����

    sizeGap = B.size() - A.size();

    for (int i = 0; i <= sizeGap; i++) {
        int cnt = 0;

        // ���� ũ���� A�� �����ϰ�, A�����ŭ B�� �߶� ������ �����Ѵ�
        for (int j = 0; j < A.size(); j++) {
            if (A[j] != B[i + j]) {
                cnt++;
            }
        }

        gap = min(gap, cnt);
    }

    cout << gap;

    return 0;
}