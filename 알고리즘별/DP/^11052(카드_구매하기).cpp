// greedy 방식이 아닌, DP를 사용한다.

// greedy 사용했더니 반례 발생
// 5
// 1 9 18 25 1
// 27이어야 하는데 26이나옵니다.
// 가성비 면에서 26이 더 높아서 27이 안 나오고 26이 출력되는 사례가 발생한 것이죠.

// 5
// 1 4 5 20 24
// 24가 나와야하는데 21이 나옴.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int idx = 0;
int ans = 0;
vector <pair <double, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        double price;

        cin >> price;

        v.push_back({price / i, i});
    }

    sort(v.begin(), v.end(), greater <pair <double, int>>());

    for (int i = 0; i < N; i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }

    while (1) {
        // 카드가 0개가 되면 탈출한다.
        if (N == 0) {
            break;
        }
        // N에서 카드 개수를 나눈 값이 1보다 크거나 같다면, 구매할 수 있다.
        if (N / v[idx].second >= 1) {
            int price = v[idx].first * v[idx].second;
            int count = N / v[idx].second;

            ans += price * count;

            N %= v[idx].second;
        }

        idx++;
    }

    cout << ans;

    return 0;
}
