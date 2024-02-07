// 9471 �ǻ�� �ֱ� ������ ���� Ǯ��ƾ� �Ѵ�.

// Ʋ�� Ǯ��
// �޸� �ʰ��� ����.
// �迭�ε�, 1000000000000000�̶�� ū ���� �ε����� ���� �� ���� ������ �� ����.

#include <iostream>
#include <vector>

using namespace std;

long long N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector <long long> v(N + 1);

    v[0] = 0;
    v[1] = 1;

    for (int i = 2; i <= N; i++) {
        v[i] = (v[i - 1] + v[i - 2]) % 1000000;
    }

    cout << v[N] % 1000000;
}



// ���� Ǯ��
// �ǻ�� �ֱ⸦ �̿��Ͽ� �ذ��Ѵ�.

#include <iostream>

using namespace std;

long long N;
long long arr[1500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= 1500000; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
    }

    cout << arr[N % 1500000];
}