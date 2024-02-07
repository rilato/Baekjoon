#include <iostream>
using namespace std;

int N;
long long D[101][11];   // 101은 N자리 수를 의미하고, 11은 0 ~ 10까지 끝 자리수를 의미
long long mod = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // 0으로 끝나면 이전 거와 개수 같음, 9로 끝나면 이전 거와 개수 같음, 나머지는 양 쪽으로

    for (int i = 1; i <= 9; i++) { // 0으로 숫자가 시작 할 수 없으므로 D[0][1]은 0으로 초기화
        D[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        D[i][0] = D[i - 1][1];        // i번째에서 끝 자리가 0이면, i - 1번째에서는 무조건 끝자리가 1이어야 함.
        D[i][9] = D[i - 1][8];        // i번째에서 끝 자리가 9이면, i - 1번째에서는 무조건 끝자리가 8이어야 함.

        // 나머지 숫자에 대해서는 i - 1번째의 두 계산 결과를 더함
        for (int j = 1; j <= 8; j++) {
            D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % mod;
        }
    }

    long sum = 0;

    for (int i = 0; i < 10; i++) {
        sum = (sum + D[N][i]) % mod; // 정답 값을 더해 줄 때도 %연산 수행
    }

    cout << sum;
}