// https://hagisilecoding.tistory.com/121
// ���Ϳ� �迭�� ������ �̿��� Ǯ�̿� �ͼ��������� �Ѵ�.
// ť�� ���� Ž���ϴ� ����, ī��Ʈ ���� �Բ� �־��ش�.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> v[102];
int a, b;
int cnt = 0; // ���� ������� ��ǥ ��� ������ �ܰ� ��

void bfs(int a, int b);

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        v[a].push_back(b); // ��� ����� �������.
        v[b].push_back(a);
    }

    int result = 987654321; // �ɺ� �������� ��
    int num = 987654321; // �ɺ� �������� ���� �ش��ϴ� ��� ��ȣ

    for (int i = 1; i <= n; i++) { // �����ϴ� ���
        int temp = 0; // �� ����� �ٸ� ������� ���� �ܰ�

        for (int j = 1; j <= n; j++) { // ��ǥ���
            if (i == j) // ���� ����� ��ǥ ����� ���� ��� �ѱ�
                continue;

            bfs(i, j);

            temp += cnt; // �� ��ǥ ����� �ܰ踦 ��� ���� �ɺ� �������� ���� ����

            cnt = 0; // ��ǥ ����� �ܰ� �ʱ�ȭ
        }

        if (result > temp) { // ���� �ɺ� �������� ���� ���Ͽ� �� ���� ���� ����
            result = temp;
            num = i;
        }

    }

    cout << num;

    return 0;
}

void bfs(int a, int b) {
    bool visit[102] = { 0, };
    queue<pair<int, int>> q;

    q.push({ a, 0 });
    visit[a] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int count = q.front().second;

        q.pop();

        if (x == b) {
            cnt = count;
            break;
        }

        for (int i = 0; i < v[x].size(); i++) {
            if (!visit[v[x][i]]) {
                q.push({ v[x][i], count + 1 });
                visit[v[x][i]] = true;
            }
        }
    }
}