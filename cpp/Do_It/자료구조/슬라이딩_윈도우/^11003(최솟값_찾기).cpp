#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, temp;
    // d에는 {index, 값}이 들어갈 것
    deque <pair <int, int>> d;

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> temp;

        // 덱의 마지막 위치에서부터 temp보다 큰 값은 덱에서 제거
        while (d.size() && d.back().second > temp) {
            d.pop_back();
        }

        // 덱의 마지막 위치에 temp값 저장
        d.push_back({ i, temp });

        // 덱의 첫 번째 위치에서부터 L의 범위를 벗어난 값은 덱에서 제거
        if (d.front().first <= i - L) {
            d.pop_front();
        }

        cout << d.front().second << ' ';
    }

    return 0;
}