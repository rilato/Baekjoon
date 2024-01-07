// 110번째 줄에서 cntRow를 해야하는데 cntCol 함수로 잘못 적어서 틀렸다..

#include <iostream>
#include <vector>

using namespace std;

int N;
int maximum = 0;
vector <vector <char>> v;

void cntRow(int i);
void cntCol(int j);
void swap1(int i, int j);
void swap2(int i, int j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N, vector <char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    // 일단 전체 탐색 (행)
    for (int i = 0; i < N; i++) {
        int temp = 1;

        for (int j = 0; j < N - 1; j++) {
            // 현재 보고있는 문자와 그 다음 문자가 다른 경우
            if (v[i][j] != v[i][j + 1]) {
                if (temp > maximum) {
                    maximum = temp;
                }

                temp = 0;
            }
            // 현재 보고있는 문자와 그 다음 문자가 같은 경우
            else {
                temp++;

                // 마지막까지 봤다면, maximum 확인 후 갱신
                if (j == N - 2 && temp > maximum) {
                    maximum = temp;
                }
            }
        }
    }

    // 일단 전체 탐색 (열)
    for (int j = 0; j < N; j++) {
        int temp = 1;

        for (int i = 0; i < N - 1; i++) {
            // 현재 보고있는 문자와 그 다음 문자가 다른 경우
            if (v[i][j] != v[i + 1][j]) {
                if (temp > maximum) {
                    maximum = temp;
                }

                temp = 0;
            }
            // 현재 보고있는 문자와 그 다음 문자가 같은 경우
            else {
                temp++;

                // 마지막까지 봤다면, maximum 확인 후 갱신
                if (i == N - 2 && temp > maximum) {
                    maximum = temp;
                }
            }
        }
    }

    // 같은 행 내에서 스왑
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (v[i][j] != v[i][j + 1]) {
                swap1(i, j);

                // 같은 행에서 maximum 개수 파악
                cntRow(i);
                // 바뀐 열에서 maximum 개수 파악
                cntCol(j);
                // 바뀐 열에서 maximum 개수 파악
                cntCol(j + 1);

                // 원래대로 돌려놓기
                swap1(i, j);
            }
        }
    }

    // 같은 열 내에서 스왑
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N - 1; i++) {
            if (v[i][j] != v[i + 1][j]) {
                swap2(i, j);

                // 바뀐 행에서 maximum 개수 파악
                cntRow(i);
                // 바뀐 행에서 maximum 개수 파악
                cntRow(i + 1);
                // 같은 열에서 maximum 개수 파악
                cntCol(j);

                // 원래대로 돌려놓기
                swap2(i, j);
            }
        }
    }

    cout << maximum;

    return 0;
}

// 같은 행끼리 탐색
void cntRow(int row) {
    int temp = 1;

    for (int j = 0; j < N - 1; j++) {
        // 현재 보고있는 문자와 그 다음 문자가 다른 경우
        if (v[row][j] != v[row][j + 1]) {
            if (temp > maximum) {
                maximum = temp;
            }

            temp = 1;
        }
        // 현재 보고있는 문자와 그 다음 문자가 같은 경우
        else {
            temp++;

            // 마지막까지 봤다면, maximum 확인 후 갱신
            if (j == N - 2 && temp > maximum) {
                maximum = temp;
            }
        }
    }
}

// 같은 열끼리 탐색
void cntCol(int col) {
    int temp = 1;

    for (int i = 0; i < N - 1; i++) {
        // 현재 보고있는 문자와 그 다음 문자가 다른 경우
        if (v[i][col] != v[i + 1][col]) {
            if (temp > maximum) {
                maximum = temp;
            }

            temp = 1;
        }
        // 현재 보고있는 문자와 그 다음 문자가 같은 경우
        else {
            temp++;

            // 마지막까지 봤다면, maximum 확인 후 갱신
            if (i == N - 2 && temp > maximum) {
                maximum = temp;
            }
        }
    }
}

void swap1(int i, int j) {
    int tmp = v[i][j];
    v[i][j] = v[i][j + 1];
    v[i][j + 1] = tmp;
}

void swap2(int i, int j) {
    int tmp = v[i][j];
    v[i][j] = v[i + 1][j];
    v[i + 1][j] = tmp;
}