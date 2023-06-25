// swap이 한 번도 일어나지 않은 루프가 언제인지 알아내는 문제
// 즉, 모든 정렬이 완료되었을 때의 i를 구하는 문제

/*
문제에서 주어진 버블 소트 알고리즘
bool changed = false;
for (int i=1; i<=N+1; i++) {
    changed = false;
    for (int j=1; j<=N-i; j++) {
        if (A[j] > A[j+1]) {
            changed = true;
            swap(A[j], A[j+1]);
        }
    }
    if (changed == false) {
        cout << i << '\n';
        break;
    }
}
*/

// 문제에서 주어진 알고리즘을 그대로 사용할 경우, 시간 초과가 발생한다.

// 시간초과가 발생하지 않으려면?

// 배열에서 연속된 숫자 2개 중, 뒤의 숫자가 작아 좌측으로 자리를 이동하는 경우는 i for문 내부에서 1번만 가능하다.
// 즉,  배열의 값이 몇 번 인덱스로 이동했는지 구하면 버블 정렬 횟수를 알아낼 수 있다.
// 정렬 전과 정렬 후의 인덱스를 비교하여 좌측으로 이동한 값 중 그 차가 가장 큰 값이 출력 값이 된다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int ans = 0;

    cin >> N;

    // first : 숫자
    // second : 기존 배열에서의 인덱스
    vector <pair <int, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        ans = max(ans, v[i].second - i);
    }

    cout << ans + 1;

    return 0;
}