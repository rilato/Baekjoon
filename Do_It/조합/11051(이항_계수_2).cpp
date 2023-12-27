#include <iostream>

using namespace std;

int N, K;
int combination[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) {
                combination[i][j] = 1;
            }
            else {
                combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]) % 10007;
            }
        }
    }

    cout << combination[N][K];

    return 0;
}
