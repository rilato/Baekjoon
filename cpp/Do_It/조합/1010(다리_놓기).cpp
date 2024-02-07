#include <iostream>

using namespace std;

int T, N, M;
int arr[31][31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    // 조합 구하기
    for (int i = 1; i < 31; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
        }
    }

    while (T--) {
        cin >> N >> M;

        cout << arr[M][N] << '\n';
    }

    return 0;
}
