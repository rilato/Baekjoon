// 짐을 가운데에 두고 양 옆에 2자리 이상 연속으로 비어있는 경우, 2로 세어주어야 한다.
// 벽을 만났을 때에도 카운트를 해준다.

#include <iostream>

using namespace std;

int N;
char arr[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int garo = 0;
    int sero = 0;

    // 가로로 연속된 빈 칸 개수 구하기
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == '.') {
                cnt++;
            }
            // 짐을 만났을 때
            else {
                if (cnt >= 2)
                    garo++; // 연속된 빈 칸이 2개 이상이면 가로로 연속된 빈 칸 개수 증가
                cnt = 0; // 연속된 빈 칸 개수 초기화
            }
        }
        // 벽을 만났을 때
        if (cnt >= 2)
            garo++; // 각 행의 마지막에 연속된 빈 칸이 있으면 가로로 연속된 빈 칸 개수 증가
    }

    // 세로로 연속된 빈 칸 개수 구하기
    for (int j = 0; j < N; j++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i][j] == '.') {
                cnt++;
            }
            // 짐을 만났을 때
            else {
                if (cnt >= 2)
                    sero++; // 연속된 빈 칸이 2개 이상이면 세로로 연속된 빈 칸 개수 증가
                cnt = 0; // 연속된 빈 칸 개수 초기화
            }
        }
        // 벽을 만났을 때
        if (cnt >= 2)
            sero++; // 각 열의 마지막에 연속된 빈 칸이 있으면 세로로 연속된 빈 칸 개수 증가
    }

    cout << garo << " " << sero;

    return 0;
}
