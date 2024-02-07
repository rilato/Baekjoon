// 주사위가 굴러가는 모습을 잘 생각해야 한다.
// https://donggoolosori.github.io/2020/11/09/boj-14499/

#include <iostream>
#include <vector>

using namespace std;

int n, m, y, x, k, num;
vector <vector <int>> v;
vector<int> dice(7); // index 1 윗면, 2 북쪽면, 3 동쪽면, 4 서쪽면, 5 남쪽면, 6 아랫면

void rollEast();
void rollWest();
void rollNorth();
void rollSouth();
void roll(int order);
void logic();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> x >> y >> k;

    v.resize(n, vector <int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> num;

        // 명령에 따라 주사위 굴리기
        roll(num);
    }

    return 0;
}

// 동쪽으로 굴리기
void rollEast() {
    dice = { 0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3] };
}

// 서쪽으로 굴리기
void rollWest() {
    dice = { 0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4] };
}

// 북쪽으로 굴리기
void rollNorth() {
    dice = { 0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };
}

// 남쪽으로 굴리기
void rollSouth() {
    dice = { 0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
}

// order에 따라 주사위 굴리기
void roll(int order) {
    switch (order) {
    case 1:
        if (y + 1 < m) {
            y++;
            rollEast();
            logic();
        }
        break;
    case 2:
        if (y - 1 >= 0) {
            y--;
            rollWest();
            logic();
        }
        break;
    case 3:
        if (x - 1 >= 0) {
            x--;
            rollNorth();
            logic();
        }
        break;
    case 4:
        if (x + 1 < n) {
            x++;
            rollSouth();
            logic();
        }
        break;
    default:
        break;
    }
}

void logic() {
    // 윗면 출력
    cout << dice[1] << '\n';

    // 도착한 보드 칸이 0 이라면
    if (v[x][y] == 0)
        v[x][y] = dice[6]; // 주사위 아랫면 숫자를 위치한 칸에 복사

    // 도착한 보드 칸이 1이라면 주사위 아랫면 숫자에 보드 칸 값 복사 & 보드 칸 0으로 만들기
    else {
        dice[6] = v[x][y];
        v[x][y] = 0;
    }
}