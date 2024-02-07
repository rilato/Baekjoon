#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
int W[1001][1001];
// �ִ� �Ÿ� �迭�� �켱���� ť �迭�� ����.
priority_queue<int> distQueue[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) { // ����ġ�� �ִ� ���� ����Ʈ �ʱ�ȭ
        int a, b, c;

        cin >> a >> b >> c;

        W[a][b] = c;
    }

    // ��� ���� 1�̰�, ����� 0.
    pq.push({ 0, 1 });
    distQueue[1].push(0);

    while (!pq.empty()) {
        pair<int, int> u = pq.top();
        pq.pop();

        for (int adjNode = 1; adjNode <= N; adjNode++) {
            // ����� ��� ��忡 ���Ͽ� �˻��ϱ� 
            if (W[u.second][adjNode] != 0) {
                // ����� ��ΰ� K���� �ȵ� ��� �׳� �߰��Ѵ�.
                if (distQueue[adjNode].size() < K) {
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push({ u.first + W[u.second][adjNode], adjNode });
                }
                // ����� ��ΰ� K���̰�, ���� ���� ū ������ �������� �߰��Ѵ�.
                else if (u.first + W[u.second][adjNode] < distQueue[adjNode].top()) {
                    distQueue[adjNode].pop(); // ���� ť���� Max�� �������� ���־����
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push({ u.first + W[u.second][adjNode], adjNode });
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) { // K��° ��� ���
        if (distQueue[i].size() == K) {
            cout << distQueue[i].top() << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}