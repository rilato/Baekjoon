#include <iostream>

using namespace std;

int n, m;
char map[50][50];
int x[50], y[50];
int xCnt = 0;
int yCnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'X') {
                x[j] = 1;
                y[i] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        // 경비원이 없는 행의 수
        if (x[i] == 0) {
            xCnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        // 경비원이 없는 열의 수
        if (y[i] == 0) {
            yCnt++;
        }
    }

    cout << max(xCnt, yCnt);

    return 0;
}
