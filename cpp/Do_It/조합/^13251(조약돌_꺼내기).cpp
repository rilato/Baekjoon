// 조합이 아닌, 단순한 확률 식을 사용해서 푼다.

#include <iostream>

using namespace std;

int N, M, K;
int total = 0;
int color[51];
double probability[51];
double ans = 0.0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> color[i];

        total += color[i];
    }

    cin >> K;

    for (int i = 0; i < M; i++) {
        if (color[i] >= K) {
            probability[i] = 1.0;

            // 현재 보고 있는 색깔에 대해같은 색이 나올 확률 구하기. ex) 5/18 + 4/17 + 3/16 + 2/15 + 1/14
            for (int j = 0; j < K; j++) {
                probability[i] *= (double)(color[i] - j) / (total - j);
            }
        }

        // 각각의 확률을 더해 정답에 더하기
        ans += probability[i];
    }

    cout << fixed;
    cout.precision(9); // 오차 범위내 출력을 위한 소수점 자리수 설정
    cout << ans;

    return 0;
}
