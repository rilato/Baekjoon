// https://yabmoons.tistory.com/617
// 왼쪽부터 시작하여 숫자를 제거하지 않고 연속합을 구했을 때 연속합의 최댓값을 구하고
// 오른쪽부터 시작하여 숫자를 제거하지 않고 연속합을 구했을 때 연속합의 최댓값을 구하여
// 두 배열 사이의 음수인 가장 작은 값을 선택하여, 그 기준의 양쪽을 나누어 더한다.

// 음수가 없는 경우 모든 수를 더한다.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
// L은 왼쪽에서부터 N을 포함한 최대 연속 합을 나타냄.
// R은 오른쪽에서부터 N을 포함한 최대 연속 합을 나타냄
vector<int> A, L, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    A.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    L.resize(N);

    L[0] = A[0];

    int result = L[0];

    for (int i = 1; i < N; i++) {
        L[i] = max(A[i], L[i - 1] + A[i]); // 왼쪽 합 배열 저장
        result = max(result, L[i]); // 하나도 제거 하지 않았을 때를 기본 최대값으로 저장
    }

    // 왼쪽 방향으로 index를 포함한 최대 연속 합 구하기.
    R.resize(N);

    R[N - 1] = A[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        R[i] = max(A[i], R[i + 1] + A[i]); // 오른쪽 합 배열 저장
    }

    // L[i - 1] + R[i + 1] 두개의 구간합 배열을 더해주면 i번째 값을 제거한 효과를 얻음
    for (int i = 1; i < N - 1; i++) {
        int temp = L[i - 1] + R[i + 1];
        result = max(result, temp);
    }

    cout << result << "\n";
}