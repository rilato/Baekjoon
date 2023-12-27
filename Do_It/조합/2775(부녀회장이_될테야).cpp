#include <iostream>

using namespace std;

int T, N, K;
int apartment[15][15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    // i는 층수 관련
    for (int i = 0; i < 15; i++) {
        // j는 호수 관련
        for (int j = 1; j < 15; j++) {
            // 0층의 각 호수 인원 초기화
            if (i == 0) {
                apartment[i][j] = j;
            }
            // 각 층의 1호는 모두 1
            else if (j == 1) {
                apartment[i][j] = 1;
            }
            // 호수 = 옆집 사람 수 + 아래집 사람 수
            else {
                apartment[i][j] = apartment[i][j - 1] + apartment[i - 1][j];
            }
        }
    }
    
    while (T--) {
        // N은 층수, K는 호수
        cin >> N >> K;

        cout << apartment[N][K] << '\n';
    }


    return 0;
}
