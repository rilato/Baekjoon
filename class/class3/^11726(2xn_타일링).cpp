// 92�� �־��� �� ���� ���� �̻�������. (������ ����)
// ������ ������ �߰��� �־��ָ� ���� ��� arr[91]�� ������ ���̰� arr[90]�� ���� ���̾ �������� ���� �ٽ� 10007�� �������� ��, ������ ���� ������ ���� �� �˾Ҵ�.
// ������ ������ �߰��� ���൵ ������ ���� ����� �������� ���ϴ� ����̹Ƿ�, ��� ����� �ٲ��� �ʳ�����.

// Ʋ�� Ǯ��

#include <iostream>

using namespace std;

int n;
long long arr[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[n] % 10007;
}


// ���� Ǯ��

#include <iostream>

using namespace std;

int n;
long long arr[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        int temp = arr[i - 1] + arr[i - 2];

        if (temp > 10007) {
            temp %= 10007;
        }

        arr[i] = temp;
    }

    cout << arr[n] % 10007;
}