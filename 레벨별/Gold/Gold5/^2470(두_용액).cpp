// Ʋ�� Ǯ��
// �ݷ� : ������ �� N�� �� �� ���� ū ���� 1000000000, 1000000000�� ������ 2000000000�̹Ƿ�, min ���� 2000000000���� �����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector <int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int start = 0; // start �� ���� ������
    int end = N - 1; // end �� ������ ������ ����
    int min = 1000000001; // ������� 0 �� ���� ������� ��
    int ansL = 0, ansR = 0;

    while (start < end) {
        int sum = v[start] + v[end];

        if (min > abs(sum)) {
            min = abs(sum);
            ansL = v[start];
            ansR = v[end];

            if (sum == 0)
                break;
        }

        // 0 ���� �����Ƿ� �� ���� ���� �� Ŀ���� 0 �� ������� ���̴�. �׷��Ƿ� �� Ŀ�����ϱ� ������ start�� ������Ų��.
        if (sum < 0)
            start++;
        // 0 ���� ũ�Ƿ� �� ���� ���� �� �۾ƾ� 0 �� ������� ���̴�. �׷��Ƿ� �� �۾������ϱ� ������ end�� ���ҽ�Ų��.
        else
            end--;
    }

    cout << ansL << " " << ansR;
}


// ���� Ǯ��
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector <int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int start = 0; // start �� ���� ������
    int end = N - 1; // end �� ������ ������ ����
    int min = 2000000000; // ������� 0 �� ���� ������� ��
    int ansL = 0, ansR = 0;

    while (start < end) {
        int sum = v[start] + v[end];

        if (min > abs(sum)) {
            min = abs(sum);
            ansL = v[start];
            ansR = v[end];

            if (sum == 0)
                break;
        }

        // 0 ���� �����Ƿ� �� ���� ���� �� Ŀ���� 0 �� ������� ���̴�. �׷��Ƿ� �� Ŀ�����ϱ� ������ start�� ������Ų��.
        if (sum < 0)
            start++;
        // 0 ���� ũ�Ƿ� �� ���� ���� �� �۾ƾ� 0 �� ������� ���̴�. �׷��Ƿ� �� �۾������ϱ� ������ end�� ���ҽ�Ų��.
        else
            end--;
    }

    cout << ansL << " " << ansR;
}