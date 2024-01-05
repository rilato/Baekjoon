#include <iostream>

using namespace std;

int N, M, K;
int combination[202][202];  // [남은 문자 총 개수][남은 z 개수]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) {
                combination[i][j] = 1;
            }
            else {
                combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];

                // K 범위가 넘어가면, 범위 최댓값 저장
                if (combination[i][j] > 1000000000) {
                    combination[i][j] = 1000000001;
                }
            }
        }
    }

    if (combination[N + M][M] < K) {
        cout << -1;
    }

    else {
        while (!(N == 0 && M == 0)) {
            // a를 선택했을 때 남은 문자로 만들 수 있는 모든 경우의 수가 K보다 크거나 같으면
            if (combination[N + M - 1][M] >= K) {
                cout << "a";
                N--;
            }
            // 모든 경우의 수가 K보다 작으면
            else {
                cout << "z";
                K = K - combination[N + M - 1][M];  // K값 업데이트
                M--;
            }
        }
    }

    return 0;
}
