// 11926과 비슷하지만, R의 횟수가 매우 커 효율적인 연산이 필요하다.
// https://howudong.tistory.com/193

#include <iostream>
#include <vector>

using namespace std;

int N, M, R, repeat, sizeN, sizeM;
vector <vector <int>> v;
// 위,왼,아래,오른
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void Rotation(int start, int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;

    v.resize(N, vector <int>(M));

    // N과 M 중 작은 수를 구하고 그 수를 2로 나누어, 전체 반복 횟수를 설정한다.
    repeat = min(N, M) / 2;

    sizeN = N;
    sizeM = M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < repeat; i++) {
        // 인덱스 i = 0 부터 시작
        // 시작 값인 인덱스와 회전 수를 인자로 넣는다.
        Rotation(i, (sizeN - 1) * 2 + (sizeM - 1) * 2);

        // 바깥쪽으로부터 안쪽으로 들어갈 때 마다 가로와 세로가 2씩 줄어들기 때문
        sizeN -= 2;
        sizeM -= 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << v[i][j] << " ";
        }

        cout << '\n';
    }

    return 0;
}

// 회전(시작 위치, 직사각형 주기)
void Rotation(int start, int size) {
    int repeat = R % size; // R을 최소화한 반복값

    while (repeat--) {
        int val = v[start][start]; // 첫 위치값
        int x = start;
        int y = start;
        int k = 0;

        // 모든 방향에 대해 반복
        while (k < 4) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // 첫 위치로 돌아오면 while문 종료
            if (nx == start && ny == start) {
                break;
            }

            // 직사각형 M과 N 범위안에 있을때만
            if ((start <= nx && nx < N - start) && (start <= ny && ny < M - start)) {
                v[x][y] = v[nx][ny]; // (x,y) : 값을 받을 위치 , (nx,ny) : 값을 줄 위치
                // 해당 위치로 x와 y를 변경
                x = nx;
                y = ny;
            }
            // 없다면 범위를 벗어난것이기 때문에 다음 방향 탐색
            else {
                k++;
            }
        }

        v[start + 1][start] = val; // 마지막 값은 비어있을테니 빼뒀던 값을 넣어둠
    }
}