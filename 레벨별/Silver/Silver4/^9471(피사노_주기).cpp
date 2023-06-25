// M은 2보다 큰 수에서, 반복되는 나머지의 맨 앞 두 개는 0과 1로 고정되어있다.
// 따라서 0과 1이 나오는 순간 주기가 시작된다.

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