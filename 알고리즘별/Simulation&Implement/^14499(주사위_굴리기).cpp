// �ֻ����� �������� ����� �� �����ؾ� �Ѵ�.
// https://donggoolosori.github.io/2020/11/09/boj-14499/

#include <iostream>
#include <vector>

using namespace std;

int n, m, y, x, k, num;
vector <vector <int>> v;
vector<int> dice(7); // index 1 ����, 2 ���ʸ�, 3 ���ʸ�, 4 ���ʸ�, 5 ���ʸ�, 6 �Ʒ���

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

        // ��ɿ� ���� �ֻ��� ������
        roll(num);
    }

    return 0;
}

// �������� ������
void rollEast() {
    dice = { 0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3] };
}

// �������� ������
void rollWest() {
    dice = { 0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4] };
}

// �������� ������
void rollNorth() {
    dice = { 0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };
}

// �������� ������
void rollSouth() {
    dice = { 0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
}

// order�� ���� �ֻ��� ������
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
    // ���� ���
    cout << dice[1] << '\n';

    // ������ ���� ĭ�� 0 �̶��
    if (v[x][y] == 0)
        v[x][y] = dice[6]; // �ֻ��� �Ʒ��� ���ڸ� ��ġ�� ĭ�� ����

    // ������ ���� ĭ�� 1�̶�� �ֻ��� �Ʒ��� ���ڿ� ���� ĭ �� ���� & ���� ĭ 0���� �����
    else {
        dice[6] = v[x][y];
        v[x][y] = 0;
    }
}