// 뒤에서부터 접근해나가는 발상을 통해 해결해야 한다.

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
        int maxNum = -1;
        long long ans = 0;

        cin >> N;

        vector <int> v(N);

        for (int j = 0; j < N; j++)
            cin >> v[j];

        for (int j = N - 1; j >= 0; j--) {
            maxNum = max(maxNum, v[j]);
            ans += maxNum - v[j];
        }

        cout << ans << '\n';
    }
}