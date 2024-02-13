// 120�̶�� �ϸ�
// 100 ~ 120 : 21�� * 3�ڸ�
// 10 ~ 99 : 90�� * 2�ڸ�
// 1 ~ 9 : 9�� * 1�ڸ�

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

    // 10 ~ 99 : 90�� * 2�ڸ�
    // 1 ~ 9 : 9�� * 1�ڸ�
    for (int i = 1; i < len; i++) {
        answer += 9 * pow(10, i - 1) * i;
    }

    // 100 ~ 120 : 21�� * 3�ڸ�
    long long division = pow(10, len - 1);
    long long cnt = N - division + 1;

    answer += cnt * len;

    cout << answer;

    return 0;
}