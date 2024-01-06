// dp���� �˾����� bfs
// �ִ� ��θ� ���� �� bfs�� ����Ѵ�

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
queue <pair <int, int>> q;
bool visited[100001] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    q.push({ N, 0 });
    visited[N] = true;

    while (!q.empty()) {
        int now = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (now == K) {
            cout << cnt;
            break;
        }

        // N���� �ϳ��� ����� �� ����, ��� ��츦 üũ�ϱ� ���ؼ� else if�� ������� �ʰ�, if���� ����Ѵ�!
        if (now - 1 >= 0 && !visited[now - 1]) {
            q.push({ now - 1, cnt + 1 });
            visited[now - 1] = true;
        }
        if (now + 1 <= 100000 && !visited[now + 1]) {
            q.push({ now + 1, cnt + 1 });
            visited[now + 1] = true;
        }
        if (now * 2 <= 100000 && !visited[now * 2]) {
            q.push({ now * 2, cnt + 1 });
            visited[now * 2] = true;
        }

        /*
        * �Ʒ��� �ڵ��, visited[now - 1]�� ���� �˻��ϱ� ������, out of bound�� �߻��� �� �ִ�!
        * �̸� ���� ����, ���� �ڵ� ó��, now - 1 >= 0�� ���� �˻��� ��, visited[now - 1]�� �˻��ϵ��� �Ѵ�.
        if (!visited[now - 1] && now - 1 >= 0) {
            q.push({ now - 1, cnt + 1 });
            visited[now - 1] = true;
        }
        if (!visited[now + 1] && now + 1 <= 100000) {
            q.push({ now + 1, cnt + 1 });
            visited[now + 1] = true;
        }
        if (!visited[now * 2] && now * 2 <= 100000) {
            q.push({ now * 2, cnt + 1 });
            visited[now * 2] = true;
        }
        */
    }

    return 0;
}