// Ʋ�� Ǯ��
// ���� ���̽��� �� ������ �ƴ�, ��� ��µǹǷ�, ������ �߻��Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> v;

    int num;
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        cin >> num;
        v.push_back(num);
        sum += num;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - v[i] - v[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j)
                        cout << v[k] << '\n';
                }
            }
        }
    }
}



// ���� Ǯ��
// ������ ���� ���� ���, �ϳ��� ����ؼ� �����ϹǷ�, return 0���� ������ ������ ��Ȯ�ϰ� ��������� �Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> v;

    int num;
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        cin >> num;
        v.push_back(num);
        sum += num;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - v[i] - v[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j)
                        cout << v[k] << '\n';
                }

                // ������ ���� ���� ��� �ϳ��� ����ؾ� �ϹǷ� ���α׷��� �����Ѵ�.
                return 0;
            }
        }
    }
}