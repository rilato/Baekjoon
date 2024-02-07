#include <iostream>

using namespace std;

int N;
int minusCnt = 0;
int plusCnt = 0;
int zeroCnt = 0;
int arr[3000][3000];

void recursive(int x, int y, int size);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    recursive(0, 0, N);

    cout << minusCnt << '\n' << zeroCnt << '\n' << plusCnt;

    return 0;
}

void recursive(int x, int y, int size) {
    int temp = arr[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != temp) {
                int len = size / 3;

                recursive(x, y, len);
                recursive(x, y + len, len);
                recursive(x, y + len + len, len);
                recursive(x + len, y, len);
                recursive(x + len, y + len, len);
                recursive(x + len, y + len + len, len);
                recursive(x + len + len, y, len);
                recursive(x + len + len, y + len, len);
                recursive(x + len + len, y + len + len, len);

                return;
            }
        }
    }

    if (temp == -1)
        minusCnt++;
    else if (temp == 1)
        plusCnt++;
    else
        zeroCnt++;
}