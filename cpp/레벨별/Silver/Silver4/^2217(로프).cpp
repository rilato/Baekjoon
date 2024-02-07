// ���� ���ڸ�, [110, 70, 20, 5, 35, 40]�� �迭�� �ִٸ� �̸� �������� �����Ͽ� [110, 70, 40, 35, 20, 5]�� �ٲپ� �� ��
// 110 * 1 / 70 * 2 / 40 * 3 / 35 * 4 / 20 * 5 / 5 * 6 �̷� ������� ����� ���� �͵� �߿��� ���� ū ���� ��������  ����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long sum = 0;
    long long result = 0;

    cin >> N;

    vector <int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < N; i++) {
        sum = v[i] * (i + 1);

        if (sum > result)
            result = sum;
    }

    cout << result;
}