// 틀린 풀이
// 반례 : 가능한 두 N의 합 중 가장 큰 값은 1000000000, 1000000000의 합으로 2000000000이므로, min 값을 2000000000으로 조정한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector <int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int start = 0; // start 은 왼쪽 끝에서
    int end = N - 1; // end 은 오른쪽 끝에서 시작
    int min = 1000000001; // 현재까지 0 에 가장 가까웠던 합
    int ansL = 0, ansR = 0;

    while (start < end) {
        int sum = v[start] + v[end];

        if (min > abs(sum)) {
            min = abs(sum);
            ansL = v[start];
            ansR = v[end];

            if (sum == 0)
                break;
        }

        // 0 보다 작으므로 두 수의 합이 더 커져야 0 에 가까워질 것이다. 그러므로 더 커져야하기 떄문에 start를 증가시킨다.
        if (sum < 0)
            start++;
        // 0 보다 크므로 두 수의 합이 더 작아야 0 에 가까워질 것이다. 그러므로 더 작아져야하기 떄문에 end를 감소시킨다.
        else
            end--;
    }

    cout << ansL << " " << ansR;
}


// 맞은 풀이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector <int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int start = 0; // start 은 왼쪽 끝에서
    int end = N - 1; // end 은 오른쪽 끝에서 시작
    int min = 2000000000; // 현재까지 0 에 가장 가까웠던 합
    int ansL = 0, ansR = 0;

    while (start < end) {
        int sum = v[start] + v[end];

        if (min > abs(sum)) {
            min = abs(sum);
            ansL = v[start];
            ansR = v[end];

            if (sum == 0)
                break;
        }

        // 0 보다 작으므로 두 수의 합이 더 커져야 0 에 가까워질 것이다. 그러므로 더 커져야하기 떄문에 start를 증가시킨다.
        if (sum < 0)
            start++;
        // 0 보다 크므로 두 수의 합이 더 작아야 0 에 가까워질 것이다. 그러므로 더 작아져야하기 떄문에 end를 감소시킨다.
        else
            end--;
    }

    cout << ansL << " " << ansR;
}