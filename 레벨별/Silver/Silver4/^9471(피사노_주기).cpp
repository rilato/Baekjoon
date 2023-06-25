// M�� 2���� ū ������, �ݺ��Ǵ� �������� �� �� �� ���� 0�� 1�� �����Ǿ��ִ�.
// ���� 0�� 1�� ������ ���� �ֱⰡ ���۵ȴ�.

#include <iostream>

using namespace std;

int P, N, M;
int arr[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> P;

    while (P--) {
        int len = 0;

        cin >> N >> M;

        arr[0] = 0;
        arr[1] = 1;

        for (int i = 2; i <= 1000000; i++) {
            arr[i] = (arr[i - 1] + arr[i - 2]) % M;
            len++;

            if (arr[i - 1] % M == 0 && arr[i] % M == 1) {
                break;
            }
        }

        cout << N << " " << len << '\n';
    }


    return 0;
}