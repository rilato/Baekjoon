// left_index와 right_index 사이의 모든 값을 더하는 문제가 아니다.
// 오직 두 개만 더해서 M이 나오는 경우만 count해야한다!!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp;
    vector <int> v;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int left_index = 0;
    int right_index = N - 1;
    int sum = 0;
    int cnt = 0;

    while (1) {
        if (left_index >= right_index)
            break;

        sum = v[left_index] + v[right_index];

        if (sum == M) {
            cnt++;
            right_index--;
            left_index++;
        }
        else if (sum < M) {
            left_index++;
        }
        else if (sum > M) {
            right_index--;
        }
    }

    cout << cnt;

    return 0;
}