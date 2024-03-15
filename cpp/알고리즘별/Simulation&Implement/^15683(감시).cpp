// Backtracking하여 조합을 찾을 때, 4번까지 돌려보며 방향을 조합하고, backup 2차원 배열을 통해 복원 작업을 병행한다.
// 또한 Check 함수에서, while문을 통해 동서남북 방향을 탐색하는 과정을 알아두어야 한다.

// 맞은 풀이
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int cctv[8][8]; // 0 빈칸, 1 ~ 5 cctv, 6 벽
int dr[4] = { 0, -1, 0, 1 }; // 0 == right, 1 == up, 2 == left, 3 == down
int dc[4] = { 1, 0, -1, 0 };
vector <pair <int, int>> cctv_pos;  // cctv의 위치 {i, j}
int res = 64;

void Backtracking(int depth);       // depth번째 cctv를 회전
void check(int r, int c, int dir);  // r,c에 위치한 cctv가 dir방향을 감시

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cctv[i][j];

            if (cctv[i][j] >= 1 && cctv[i][j] <= 5) {
                cctv_pos.push_back({ i, j });
            }
        }
    }

    Backtracking(0);

    cout << res;

    return 0;
}

// depth번째 cctv를 회전
void Backtracking(int depth) {
    if (depth == cctv_pos.size()) { //모든 cctv를 다 확인했을 때
        int temp_res = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cctv[i][j] == 0)
                    temp_res++;
            }
        }

        res = min(res, temp_res);

        return;
    }

    int r = cctv_pos[depth].first;
    int c = cctv_pos[depth].second;
    int backup[8][8];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            backup[i][j] = cctv[i][j];
        }
    }

    for (int dir = 0; dir < 4; dir++) { //4번까지 회전시켜본다
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                backup[i][j] = cctv[i][j];
            }
        }

        /* dir 1증가하면 90도 회전, 재귀 함수 들어가기 전, 경우를 모두 탐색 */
        if (cctv[r][c] == 1) {
            check(r, c, dir); //dir == 0 일때 right
        }
        else if (cctv[r][c] == 2) {
            check(r, c, dir); //dir == 0 일때 right
            check(r, c, dir + 2); //dir == 0 일때 left

        }
        else if (cctv[r][c] == 3) {
            check(r, c, dir); //dir == 0 일때 right
            check(r, c, dir + 1); //dir == 0 일때 up
        }
        else if (cctv[r][c] == 4) {
            check(r, c, dir); //dir == 0 일때 right
            check(r, c, dir + 1); //dir == 0 일때 up
            check(r, c, dir + 2); //dir == 0 일때 left

        }
        else if (cctv[r][c] == 5) {
            check(r, c, dir); //dir == 0 일때 right
            check(r, c, dir + 1); //dir == 0 일때 up
            check(r, c, dir + 2); //dir == 0 일때 left
            check(r, c, dir + 3); //dir == 0 일때 down
        }

        //다음 cctv 회전시키기 위해 백트래킹
        Backtracking(depth + 1);

        // 복원 작업
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cctv[i][j] = backup[i][j];
            }
        }
    }
}

// r,c에 위치한 cctv가 dir방향을 감시
void check(int r, int c, int dir) {
    dir %= 4; // 가능한 감시방향 right, up, left, down (0 ~ 3)

    while (true) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        r = nr;
        c = nc;

        if (nr < 0 || nc < 0 || nr >= N || nc >= M || cctv[nr][nc] == 6)
            return;

        if (cctv[nr][nc] != 0)
            continue;

        cctv[nr][nc] = '#';
    }
}


// 처음에 시도했지만, 시간초과 + 틀린 풀이

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int cctv = 0;      // 탐색할 CCTV의 총 개수
int zeroCount = 0;
int minimum = INT_MAX;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
vector <vector <int>> v;
vector <pair <int, int>> index; // { row, col }
vector <bool> visit;            // index 방문 여부
vector <vector <bool>> visited; // index에 해당하는 4가지 방향의 dir의 방문 여부
vector <int> direction;              // index에 해당하는 dir값 푸시

void Backtracking(int depth);
void One(int r, int c, int d);
void Two(int r, int c, int d);
void Three(int r, int c, int d);
void Four(int r, int c, int d);
void Five(int r, int c, int d);
void Up(int r, int c);
void Down(int r, int c);
void Left(int r, int c);
void Right(int r, int c);
void Check();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(N, vector <int>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];

            if (v[i][j] == 0) {
                ++zeroCount;
            }

            if (1 <= v[i][j] && v[i][j] <= 5) {
                ++cctv;
                index.push_back({ i, j });
            }
        }
    }

    // index의 방문 여부를 기록하므로, size는 index.size()
    visit.resize(index.size());
    // index마다 상하좌우 네 방향 있으므로 4
    visited.resize(index.size(), vector <bool>(4));

    // 순열 구하기
    Backtracking(0);

    cout << minimum;

    return 0;
}

void Backtracking(int depth) {
    if (depth == cctv) {
        for (int i = 0; i < direction.size(); i++) {
            int row = index[i].first;
            int col = index[i].second;
            int number = v[row][col];

            //cout << "i : " << i << ", row : " << row << ", col : " << col << ", number : " << number << '\n';

            switch(number) {
            case 1:
                //cout << "One\n";
                One(row, col, direction[i]);
                break;
            case 2:
                //cout << "Two\n";
                Two(row, col, direction[i]);
                break;
            case 3:
                //cout << "Three\n";
                Three(row, col, direction[i]);
                break;
            case 4:
                //cout << "Four\n";
                Four(row, col, direction[i]);
                break;
            default:
                //cout << "Five\n";
                Five(row, col, direction[i]);
                break;
            }
        }

        Check();

        //cout << '\n';

        return;
    }

    for (int i = 0; i < index.size(); ++i) {
        if (!visit[i]) {
            visit[i] = true;

            for (int j = 0; j < 4; ++j) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    direction.push_back(j);
                    Backtracking(depth + 1);
                    direction.pop_back();
                    visited[i][j] = false;
                }
            }

            visit[i] = false;
        }
    }
}

void One(int r, int c, int d) {
    //상
    if (d == 0) {
        //cout << "Up\n";
        Up(r, c);
    }

    //하
    if (d == 1) {
        //cout << "Down\n";
        Down(r, c);
    }

    //좌
    if (d == 2) {
        //cout << "Left\n";
        Left(r, c);
    }

    //우
    if (d == 3) {
        //cout << "Right\n";
        Right(r, c);
    }
}

void Two(int r, int c, int d) {
    // 상하
    if (d % 2 == 0) {
        //cout << "Up, Down\n";
        Up(r, c);
        Down(r, c);
    }

    // 좌우
    else {
        //cout << "Left, Right\n";
        Left(r, c);
        Right(r, c);
    }
}

void Three(int r, int c, int d) {
    // 상우
    if (d == 0) {
        //cout << "Up, Right\n";
        Up(r, c);
        Right(r, c);
    }

    // 우하
    if (d == 1) {
        //cout << "Down, Right\n";
        Down(r, c);
        Right(r, c);
    }

    // 하좌
    if (d == 2) {
        //cout << "Down, Left\n";
        Down(r, c);
        Left(r, c);
    }

    // 좌상
    if (d == 3) {
        //cout << "Up, Left\n";
        Up(r, c);
        Left(r, c);
    }
}

void Four(int r, int c, int d) {
    // ㅏ
    if (d == 0) {
        //cout << "Up, Down, Right\n";
        Up(r, c);
        Down(r, c);
        Right(r, c);
    }

    // ㅜ
    if (d == 1) {
        //cout << "Down, Left, Right\n";
        Down(r, c);
        Left(r, c);
        Right(r, c);
    }

    // ㅓ
    if (d == 2) {
        //cout << "Up, Down, Left\n";
        Up(r, c);
        Down(r, c);
        Left(r, c);
    }

    // ㅗ
    if (d == 3) {
        //cout << "Up, Left, Right\n";
        Up(r, c);
        Left(r, c);
        Right(r, c);
    }
}

void Five(int r, int c, int d) {
    // 상하좌우
    //cout << "Up, Down, Left, Right\n";
    Up(r, c);
    Down(r, c);
    Left(r, c);
    Right(r, c);
}

void Up(int r, int c) {
    for (int i = r; i >= 0; i--) {
        if (v[i][c] == 6) {
            break;
        }
        else if (v[i][c] == 0) {
            v[i][c] = -1;
        }
    }
}

void Down(int r, int c) {
    for (int i = r; i < N; i++) {
        if (v[i][c] == 6) {
            break;
        }
        else if (v[i][c] == 0) {
            v[i][c] = -1;
        }
    }
}

void Left(int r, int c) {
    for (int j = c; j >= 0; j--) {
        if (v[r][j] == 6) {
            break;
        }
        else if (v[r][j] == 0) {
            v[r][j] = -1;
        }
    }
}

void Right(int r, int c) {
    for (int j = c; j < N; j++) {
        if (v[r][j] == 6) {
            break;
        }
        else if (v[r][j] == 0) {
            v[r][j] = -1;
        }
    }
}

void Check() {
    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // 사각지대 카운팅
            if (v[i][j] == 0) {
                ++cnt;
            }

            // -1이라면, CCTV에 의해 감시당하는 곳으로, 원상복구 시켜준다.
            else if (v[i][j] == -1) {
                v[i][j] = 0;
            }
        }
    }

    minimum = min(minimum, cnt);

    //cout << "minimum : " << minimum << '\n';
}
