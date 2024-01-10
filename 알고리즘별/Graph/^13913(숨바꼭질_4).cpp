#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
vector <bool> visited;
vector <int> parent;        // ���� �ٶ󺸴� index�� �θ� ��δ� index�� ��, index�� ���� �ڽİ�δ� index
// parent �迭�� �ִ� �ð��� ���ϴ� �� ��������, �� �� ������ ���� �ٸ� ������ �������̵� ���� �ʴ� �� ����.
queue <pair<int, int>> q;   // {��ġ, �ð�} ����
vector <int> answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    visited.resize(100001);
    parent.resize(100001);

    q.push({ N, 0 });
    visited[N] = true;

    while (!q.empty()) {
        int now = q.front().first;
        int time = q.front().second;

        q.pop();

        if (now == K) {
            int index = now;

            while (index != N) {
                answer.push_back(index);    // ���� ���� �ִ� ��� �ֱ�
                index = parent[index];      // index = �θ� ��η� ����
            }

            // �� ó�� �� �ֱ�
            answer.push_back(N);

            cout << time << '\n';

            break;
        }

        if (now - 1 >= 0 && !visited[now - 1]) {
            visited[now - 1] = true;
            q.push({ now - 1, time + 1 });
            parent[now - 1] = now;
        }
        if (now + 1 <= 100000 && !visited[now + 1]) {
            visited[now + 1] = true;
            q.push({ now + 1, time + 1 });
            parent[now + 1] = now;
        }
        if (now * 2 <= 100000 && !visited[now * 2]) {
            visited[now * 2] = true;
            q.push({ now * 2, time + 1 });
            parent[now * 2] = now;
        }
    }

    for (int i = answer.size() - 1; i >= 0; i--) {
        cout << answer[i] << " ";
    }

    return 0;
}