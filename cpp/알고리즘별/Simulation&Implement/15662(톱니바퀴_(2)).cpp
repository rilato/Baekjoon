#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, K, tnum, direction;
string S;
int cnt = 0;
int dx[2] = { -1, 1 };
vector <vector <int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    v.resize(T + 1, vector <int>(8));

    for (int i = 1; i <= T; i++) {
        cin >> S;

        for (int j = 0; j < S.size(); j++) {
            v[i][j] = S[j] - '0';
        }
    }

    // 2�� �ε����� ����, 6�� �ε����� ����
    // 2���� 6���� �´���

    cin >> K;

    while (K--) {
        cin >> tnum >> direction;

        // ȸ���ؾ��� ��Ϲ����� ȸ�� ������ ����
        vector <pair<int, int>> tmp;
        queue <pair <int, int>> q;
        vector <bool> visited(T + 1);
        // leftFlag�� true�� ��쿡�� ���� ��Ϲ����� ȸ�� ����
        bool leftFlag = true;
        // rightFlag�� true�� ��쿡�� ������ ��Ϲ����� ȸ�� ����
        bool rightFlag = true;

        q.push({ tnum, direction });
        visited[tnum] = true;
        tmp.push_back({ tnum, direction });

        while (!q.empty()) {
            int now = q.front().first;
            int nowDirection = q.front().second;
            q.pop();

            for (int i = 0; i < 2; i++) {
                int next = now + dx[i];
                int nextDirection = (nowDirection == 1 ? -1 : 1);

                // ���� �Ѿ�� Ž�� ����
                if (next < 1 || next > T) {
                    continue;
                }

                if (!visited[next]) {
                    // �ϴ� �湮�� ���� ���� �湮ó��
                    visited[next] = true;

                    // ���� �湮�� ���� �� ũ�ٴ� ����, ���� �湮�� ���� �������� ������ ������ �ǹ���
                    // ���� ������ ���� ��Ϲ����� ������ ���� ��Ϲ����� ���ؾ� ��
                    if (rightFlag && next > now && v[now][2] != v[next][6]) {
                        q.push({ next, nextDirection });
                        tmp.push_back({ next, nextDirection });
                    }
                    // ���� �湮�� ���� �� �۴ٴ� ����, ���� �湮�� ���� �������� ������ ������ �ǹ���
                    // ���� ������ ���� ��Ϲ����� ������ ���� ��Ϲ����� ���ؾ� ��
                    else if (leftFlag && next < now && v[now][6] != v[next][2]) {
                        q.push({ next, nextDirection });
                        tmp.push_back({ next, nextDirection });
                    }
                    // �� �̿��� ���� ���� �湮�� ������ ��Ϲ����� ��ȭ�� ������ �ǹ�
                    else {
                        if (next > now) {
                            rightFlag = false;
                        }
                        else {
                            leftFlag = false;
                        }
                        q.push({ next, nowDirection });
                    }
                }
            }
        }

        // �������� ��Ϲ����� ã�� ������
        for (int i = 0; i < tmp.size(); i++) {
            int t = tmp[i].first;
            int d = tmp[i].second;

            // �ð� ���� ȸ��
            if (d == 1) {
                int temp = v[t][7];

                for (int j = 6; j >= 0; j--) {
                    v[t][j + 1] = v[t][j];
                }

                v[t][0] = temp;
            }
            // �ݽð� ���� ȸ��
            if (d == -1) {
                int temp = v[t][0];

                for (int j = 0; j <= 6; j++) {
                    v[t][j] = v[t][j + 1];
                }

                v[t][7] = temp;
            }
        }
    }

    // S�� ���� ã��
    for (int i = 1; i <= T; i++) {
        if (v[i][0] == 1) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}