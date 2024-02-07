// 예를 들자면, [110, 70, 20, 5, 35, 40]의 배열이 있다면 이를 내림차순 정렬하여 [110, 70, 40, 35, 20, 5]로 바꾸어 준 후
// 110 * 1 / 70 * 2 / 40 * 3 / 35 * 4 / 20 * 5 / 5 * 6 이런 순서대로 계산을 해준 것들 중에서 가장 큰 값을 정답으로  출력한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long sum = 0;
    long long result = 0;

    cin >> N;

    vector <int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < N; i++) {
        sum = v[i] * (i + 1);

        if (sum > result)
            result = sum;
    }

    cout << result;
}