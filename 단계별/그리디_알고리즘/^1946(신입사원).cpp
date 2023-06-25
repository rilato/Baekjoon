// 문제가 잘 이해되지 않았다.
// 문제를 잘 이해해보자.
// https://tooo1.tistory.com/245

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, N;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        vector <pair <int, int>> v;
        int a, b, temp;
        // 첫 번째 사원은 무조건 선발
        int ans = 1;

        for (int j = 0; j < N; j++) {
            cin >> a >> b;

            v.push_back({ a,b });
        }

        sort(v.begin(), v.end());

        temp = v[0].second;

        for (int j = 1; j < N; j++) {
            if (temp > v[j].second) {
                ++ans;
                temp = v[j].second;
            }
        }

        cout << ans << '\n';
    }
}