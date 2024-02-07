// DFS BFS ��� ����ؼ� Ǯ�����

#include <iostream>
#include <queue>

using namespace std;

#define MAX 101

int N, M; //��������, ��������, ��������
int map[MAX][MAX]; //���� ��� �׷���
bool visited[MAX]; //���� �湮 ����
int cnt = 0;
queue<int> q;

void reset();
void DFS(int v);
//void BFS(int v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;

        cin >> a >> b;

        // a�� b�� ������������ (a,b) �� (b,a) ��� ��Ŀ��� 1�� ����
        map[a][b] = 1;
        map[b][a] = 1;
    }

    DFS(1);

    //cout << cnt << '\n';

    //cnt = 0;

    //reset();
    //BFS(1);

    cout << cnt;

    return 0;
}

void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

void DFS(int v) {
    // ���ڷ� ���� ������ ���� �湮�� �����̹Ƿ� true�� ����
    visited[v] = true;

    // N�� ����� ����
    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && visited[i] == 0) { //���� ������ ����Ǿ��ְ� �湮���� �ʾ�����
            ++cnt;
            DFS(i);
        }
    }
}

void BFS(int v) {
    // ���ڷ� ���� ������ ���� ť�� Ǫ��
    q.push(v);
    // �湮�� �����̹Ƿ� true�� ����
    visited[v] = true;

    // ť�� ���ִ� ���� ��� ����
    while (!q.empty()) {
        v = q.front();

        q.pop();

        // N�� ����� ����
        for (int i = 1; i <= N; i++) {
            if (map[v][i] == 1 && visited[i] == 0) { //���� ������ ����Ǿ��ְ� �湮���� �ʾ�����
                ++cnt;
                // �� �ָ� ť�� Ǫ��
                q.push(i);
                // �湮�ߴٰ� ǥ��
                visited[i] = true;
            }
        }
    }
}