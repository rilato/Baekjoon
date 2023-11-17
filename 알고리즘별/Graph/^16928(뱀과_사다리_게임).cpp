#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[101];
bool visited[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    // ��ٸ� �Է�, �� �Է�
    for (int i = 0; i < n + m; i++) {
        int u, v;

        cin >> u >> v;

        map[u] = v;
    }

    queue<pair<int, int>> q;

    // �� ó��, �������� 1, ī��Ʈ�� 0
    q.push({ 1, 0 });

    while (!q.empty()) {
        int x = q.front().first;    // ���� �����ִ� ��ǥ
        int cnt = q.front().second; // ī��Ʈ ��

        q.pop();

        for (int i = 1; i <= 6; i++) {
            int nextX = x + i;  // ������ ��������� ��ǥ

            if (nextX == 100) {     // ���� ��, cnt + 1�� ���
                cout << cnt + 1;
                return 0;
            }
            else if (nextX < 100) {     // 100���� �۰�, ���� ������ ���
                if (map[nextX] != 0) {  // ��ٸ��� �ִ��� ���� Ȯ��
                    nextX = map[nextX]; // ��ٸ��� �ִٸ�, ������ ��������� ��ǥ�� ������Ʈ
                }
                if (!visited[nextX]) {  // ������ ��������� ��ǥ�� �湮���� �ʾҴٸ�, �ش� ��ǥ�� cnt + 1�� ť�� Ǫ��
                    q.push({ nextX, cnt + 1 });
                    visited[nextX] = true;
                }
            }
        }
    }

    return 0;
}