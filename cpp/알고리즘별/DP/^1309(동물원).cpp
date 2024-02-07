// 내가 풀었지만, 우연히 맞은 풀이

#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N + 1);

    v[1] = 3;
    v[2] = 7;

    for (int i = 3; i <= N; i++) {
        v[i] = (v[i - 1] * 2 + v[i - 2]) % 9901;
    }

    cout << v[N] % 9901;

    return 0;
}

// 정석 풀이
// https://yabmoons.tistory.com/137

#include <iostream>
#include <vector>

using namespace std;

int N;
vector <vector <int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N + 1, vector <int>(3));

    // v[N][0] : N번째 줄에 사자를 배치하지 않는 경우
    // v[N][1] : N번째 줄에서 왼쪽에 사자를 배치하는 경우
    // v[N][2] : N번째 줄에서 오른쪽에 사자를 배치하는 경우

    v[1][0] = 1;    // N = 1일 때, 사자가 배치되지 않는 경우는 1이다.
    v[1][1] = 1;    // N = 1일 때, 왼쪽에 사자가 배치되는 경우는 1이다.
    v[1][2] = 1;    // N = 1일 때, 오른쪽에 사자가 배치되는 경우는 1이다.

    for (int i = 2; i <= N; i++) {
        // i번째 줄에 사자가 배치되지 않는다면,
        // i - 1번째 줄에서는 사자가 배치되지 않아도 되고 (v[i - 1][0]),
        // 왼쪽에 사자가 배치되어 있어도 되고 (v[i - 1][1]),
        // 오른쪽에 사자가 배치되어 있어도 된다 (v[i - 1][2])
        v[i][0] = (v[i - 1][0] + v[i - 1][1] + v[i - 1][2]) % 9901;

        // i번째 줄, 왼쪽에 사자가 베치된다면,
        // i - 1번째 줄에서는 사자가 배치되지 않아도 되고 (v[i - 1][0]),
        // 오른쪽에 사자가 배치되어 있어도 된다 (v[i - 1][2])
        v[i][1] = (v[i - 1][0] + v[i - 1][2]) % 9901;

        // i번째 줄, 오른쪽에 사자가 베치된다면,
        // i - 1번째 줄에서는 사자가 배치되지 않아도 되고 (v[i - 1][0]),
        // 왼쪽에 사자가 배치되어 있어도 된다 (v[i - 1][1])
        v[i][2] = (v[i - 1][0] + v[i - 1][1]) % 9901;
    }

    cout << (v[N][0] + v[N][1] + v[N][2]) % 9901;

    return 0;
}