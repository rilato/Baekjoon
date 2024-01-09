#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, k;
int maximum = 0;
bool flag = false;
vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = N - 1; i > 0; i--) {
        // �Ųٷ� ���Ǹ鼭 ���� ���ڰ� ���� ���ں��� ũ�ٸ�, flag�� true�� �ٲٰ�, �ڿ� ������ ���� �� ���� ũ�鼭, v[i - 1]���ٴ� ���� �� ���ڸ� �ٲ۴�.
        // (���� ���, 5 1 3 2 4���, �ڿ������� Ž������ �� 5 > 1 �̹Ƿ�, 1���� ������ �� ��, 5 ���� ���� ���� �� ���� ū ������ 4�� �ٲ۴�.
        // 5 1 2 3 4 -> 4 1 2 3 5
        // ���� 1���� 5���� ���� ������������ �����Ѵ�.
        if (v[i - 1] > v[i]) {
            flag = true;

            // v[i - 1]���� ���� ���� ��, maximum ���� ã�´�.
            for (int j = i; j < N; j++) {
                if (v[j] < v[i - 1] && v[j] > maximum) {
                    k = j;
                    maximum = v[j];
                }
            }

            int temp = v[k];
            v[k] = v[i - 1];
            v[i - 1] = temp;

            // �ٲ� ���� �ٷ� �ڱ��� ������������ �����Ѵ�. (5 1 2 3 4 -> 4 1 2 3 5 -> 5�� 4�� �ٲ���µ�, ���� 5 �ٷ� �ڿ� �ִ� 1���� �������� ����)
            sort(v.begin() + i, v.end(), greater <int>());

            break;
        }
    }

    if (flag) {
        for (int i = 0; i < N; i++) {
            cout << v[i] << " ";
        }
    }
    else {
        cout << -1;
    }

    return 0;
}