// https://howudong.tistory.com/172

#include <iostream>
#include <vector>

using namespace std;

int N, M, R;
vector <vector <int>> v;

void Rotation();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;

    v.resize(N, vector <int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        Rotation();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j] << " ";
        }

        cout << '\n';
    }

    return 0;
}

void Rotation() {
    vector <vector <int>> temp;
    temp.resize(N, vector <int>(M));

    // 반복 횟수 = N과 M중 작은 수 / 2
    int repeat = min(N, M) / 2;

    // 해당 위치 방문 확인
    vector <vector <bool>> visited;

    visited.resize(N, vector <bool>(M));

    for (int size = 0; size < repeat; size++) {
        // size -> 사각형 테두리 시작점
        int cntX = size, cntY = size;

        // 다시 한번 시작위치를 방문할 때 까지 반복
        while (!visited[cntX][cntY]) {
            visited[cntX][cntY] = true;
            // 위 일때 (오른쪽 모퉁이는 바로 아래 줄에서 커버)
            if (cntX == size && cntY != M - 1 - size) {
                // temp 현재 위치에 v의 다음 위치 값을 담아줌
                temp[cntX][cntY] = v[cntX][cntY + 1];
                cntY++;
            }
            // 오른쪽 일 때 (아래쪽 모퉁이는 바로 아래 줄에서 커버)
            else if (cntY == M - 1 - size && cntX != N - 1 - size) {
                temp[cntX][cntY] = v[cntX + 1][cntY];
                cntX++;
            }
            // 아래 일 때 (왼쪽 모퉁이는 바로 아래 줄에서 커버)
            else if (cntX == N - 1 - size && cntY != size) {
                temp[cntX][cntY] = v[cntX][cntY - 1];
                cntY--;
            }
            // 왼쪽 일 때 (위쪽 모퉁이는 맨 위 줄에서 커버)
            else if (cntY == size && cntX != size) {
                temp[cntX][cntY] = v[cntX - 1][cntY];
                cntX--;
            }
        }
    }

    v = temp;
}