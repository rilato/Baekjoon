// 120이라고 하면
// 100 ~ 120 : 21개 * 3자리
// 10 ~ 99 : 90개 * 2자리
// 1 ~ 9 : 9개 * 1자리

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string S;
int N, len;
long long answer = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;

    N = stoi(S);
    len = S.length();

    // 10 ~ 99 : 90개 * 2자리
    // 1 ~ 9 : 9개 * 1자리
    for (int i = 1; i < len; i++) {
        answer += 9 * pow(10, i - 1) * i;
    }

    // 100 ~ 120 : 21개 * 3자리
    long long division = pow(10, len - 1);
    long long cnt = N - division + 1;

    answer += cnt * len;

    cout << answer;

    return 0;
}