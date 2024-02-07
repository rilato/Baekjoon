// visited �迭�� '�ִ�' �湮 �Ÿ��� ������Ʈ�� ������.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, x;
vector <vector <int>> A;
vector <int> answer;
vector <int> visited;   // �湮 �Ÿ��� �����ϴ� �迭

void BFS(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> x;

    A.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int s, e;

        cin >> s >> e;

        // ������ �ִ� �׷����̹Ƿ�, A[s].push_back(e);�� ����
        A[s].push_back(e);
    }

    for (int i = 0; i <= n; i++) {
        visited[i] = -1;
    }

    BFS(x);

    // �湮 �Ÿ��� k�� ����� ���ڸ� ���� �迭�� �ֱ�
    for (int i = 0; i <= n; i++) {
        if (visited[i] == k) {
            answer.push_back(i);
        }
    }

    if (answer.empty()) {
        cout << -1;
    }

    else {
        sort(answer.begin(), answer.end());

        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << '\n';
        }
    }

    return 0;
}

void BFS(int x) {
    queue <int> q;

    // ��� ��� �ֱ�
    q.push(x);
    // visited �迭�� ���� ��� �湮 ���
    visited[x]++;

    while (!q.empty()) {
        // ť���� ��� ������ ��������
        int now_x = q.front();

        q.pop();

        // ���� ���� �ִ� ���� ����� ��� i ��, ���� �湮���� ���� ��� (visited[i] == -1),
        // visited�迭�� �湮 �Ÿ��� ������Ʈ �� ��, ť�� i push
        for (int j = 0; j < A[now_x].size(); j++) {
            int i = A[now_x][j];

            if (visited[i] == -1) {
                visited[i] = visited[now_x] + 1;
                q.push(i);
            }
        }
    }
}