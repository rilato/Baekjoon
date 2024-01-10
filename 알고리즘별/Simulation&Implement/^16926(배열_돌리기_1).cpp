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

    // �ݺ� Ƚ�� = N�� M�� ���� �� / 2
    int repeat = min(N, M) / 2;

    // �ش� ��ġ �湮 Ȯ��
    vector <vector <bool>> visited;

    visited.resize(N, vector <bool>(M));

    for (int size = 0; size < repeat; size++) {
        // size -> �簢�� �׵θ� ������
        int cntX = size, cntY = size;

        // �ٽ� �ѹ� ������ġ�� �湮�� �� ���� �ݺ�
        while (!visited[cntX][cntY]) {
            visited[cntX][cntY] = true;
            // �� �϶� (������ �����̴� �ٷ� �Ʒ� �ٿ��� Ŀ��)
            if (cntX == size && cntY != M - 1 - size) {
                // temp ���� ��ġ�� v�� ���� ��ġ ���� �����
                temp[cntX][cntY] = v[cntX][cntY + 1];
                cntY++;
            }
            // ������ �� �� (�Ʒ��� �����̴� �ٷ� �Ʒ� �ٿ��� Ŀ��)
            else if (cntY == M - 1 - size && cntX != N - 1 - size) {
                temp[cntX][cntY] = v[cntX + 1][cntY];
                cntX++;
            }
            // �Ʒ� �� �� (���� �����̴� �ٷ� �Ʒ� �ٿ��� Ŀ��)
            else if (cntX == N - 1 - size && cntY != size) {
                temp[cntX][cntY] = v[cntX][cntY - 1];
                cntY--;
            }
            // ���� �� �� (���� �����̴� �� �� �ٿ��� Ŀ��)
            else if (cntY == size && cntX != size) {
                temp[cntX][cntY] = v[cntX - 1][cntY];
                cntX--;
            }
        }
    }

    v = temp;
}