// 어차피 1부터 N까지 쭉 이어지는 수를 대상으로 조사하므로,
// 벡터를 따로 만들지 않고 바로 while문 사용

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int sum = 0;
    int cnt = 0;
    int left_index = 0;
    int right_index = 0;

    cin >> N;

    while (1) {
        if (left_index == N + 1)
            break;

        if (sum == N) {
            cnt++;
            right_index++;
            sum += right_index;
        }
        else if (sum > N) {
            left_index++;
            sum -= left_index;
        }
        else if (sum < N) {
            right_index++;
            sum += right_index;
        }
    }

    cout << cnt;

    return 0;
}