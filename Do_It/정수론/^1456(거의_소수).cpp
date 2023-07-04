#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long Min, Max;
long A[10000001];
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Min >> Max;

    // 제곱이 10^14 범위이기 때문에 10^7까지만 반복
    for (int i = 2; i < 10000001; i++) {
        A[i] = i;
    }

    for (int i = 2; i <= sqrt(10000001); i++) { // 제곱근까지만 수행
        // 소수가 아니면 skip
        if (A[i] == 0) {
            continue;
        }

        // 소수이면 소수는 놔두고 배수 지우기
        for (int j = i + i; j < 10000001; j += i) {
            A[j] = 0;
        }
    }

    for (int i = 2; i < 10000001; i++) {
        if (A[i] != 0) {
            // A[i]는 현재 소수
            long temp = A[i];

            // 현재 소수(A[i])의 제곱근이 Max보다 작을 때 기준이지만
            // A[i]와 temp의 곱셈이 long의 범위를 넘어갈 수 있어 우항으로 곱하기를 넘겨 나누기로 바꾸어 처리
            while ((double)A[i] <= (double)Max / (double)temp) {
                if ((double)A[i] >= (double)Min / (double)temp) {
                    cnt++;
                }

                // temp를 A[i]의 N제곱으로 갱신하여 넣기
                temp *= A[i];
            }
        }
    }

    cout << cnt;
}