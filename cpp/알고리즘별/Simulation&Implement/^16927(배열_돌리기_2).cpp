// 11926�� ���������, R�� Ƚ���� �ſ� Ŀ ȿ������ ������ �ʿ��ϴ�.
// https://howudong.tistory.com/193

#include <iostream>
#include <vector>

using namespace std;

int N, M, R, repeat, sizeN, sizeM;
vector <vector <int>> v;
// ��,��,�Ʒ�,����
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void Rotation(int start, int size);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;

    v.resize(N, vector <int>(M));

    // N�� M �� ���� ���� ���ϰ� �� ���� 2�� ������, ��ü �ݺ� Ƚ���� �����Ѵ�.
    repeat = min(N, M) / 2;

    sizeN = N;
    sizeM = M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < repeat; i++) {
        // �ε��� i = 0 ���� ����
        // ���� ���� �ε����� ȸ�� ���� ���ڷ� �ִ´�.
        Rotation(i, (sizeN - 1) * 2 + (sizeM - 1) * 2);

        // �ٱ������κ��� �������� �� �� ���� ���ο� ���ΰ� 2�� �پ��� ����
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

// ȸ��(���� ��ġ, ���簢�� �ֱ�)
void Rotation(int start, int size) {
    int repeat = R % size; // R�� �ּ�ȭ�� �ݺ���

    while (repeat--) {
        int val = v[start][start]; // ù ��ġ��
        int x = start;
        int y = start;
        int k = 0;

        // ��� ���⿡ ���� �ݺ�
        while (k < 4) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // ù ��ġ�� ���ƿ��� while�� ����
            if (nx == start && ny == start) {
                break;
            }

            // ���簢�� M�� N �����ȿ� ��������
            if ((start <= nx && nx < N - start) && (start <= ny && ny < M - start)) {
                v[x][y] = v[nx][ny]; // (x,y) : ���� ���� ��ġ , (nx,ny) : ���� �� ��ġ
                // �ش� ��ġ�� x�� y�� ����
                x = nx;
                y = ny;
            }
            // ���ٸ� ������ ������̱� ������ ���� ���� Ž��
            else {
                k++;
            }
        }

        v[start + 1][start] = val; // ������ ���� ��������״� ���״� ���� �־��
    }
}