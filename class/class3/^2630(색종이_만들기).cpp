// 이전에 풀었던 1074 ( Z ) 와 유사한 구조를 갖는 문제

#include <iostream>

using namespace std;

int N;
int arr[129][129];
int Blue = 0;
int White = 0;

void recursive(int y, int x, int size);

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

    cout << White << "\n" << Blue;
}

void recursive(int y, int x, int size) {
    int color = arr[y][x];

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            // 색이 다르다면, 색종이 쪼개기 진행
            if (arr[i][j] != color) {
                int len = size / 2;

                recursive(y, x, len);
                recursive(y, x + len, len);
                recursive(y + len, x, len);
                recursive(y + len, x + len, len);

                return;
            }
        }
    }

    if (color == 1)
        Blue++;
    else
        White++;
}