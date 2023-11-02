#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
int W[1001][1001];
// 최단 거리 배열을 우선순위 큐 배열로 선언.
priority_queue<int> distQueue[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) { // 가중치가 있는 인접 리스트 초기화
        int a, b, c;

        cin >> a >> b >> c;

        W[a][b] = c;
    }

    // 출발 노드는 1이고, 비용은 0.
    pq.push({ 0, 1 });
    distQueue[1].push(0);

    while (!pq.empty()) {
        pair<int, int> u = pq.top();
        pq.pop();

        for (int adjNode = 1; adjNode <= N; adjNode++) {
            // 연결된 모든 노드에 대하여 검색하기 
            if (W[u.second][adjNode] != 0) {
                // 저장된 경로가 K개가 안될 경우 그냥 추가한다.
                if (distQueue[adjNode].size() < K) {
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push({ u.first + W[u.second][adjNode], adjNode });
                }
                // 저장된 경로가 K개이고, 현재 가장 큰 값보다 작을때만 추가한다.
                else if (u.first + W[u.second][adjNode] < distQueue[adjNode].top()) {
                    distQueue[adjNode].pop(); // 기존 큐에서 Max값 삭제먼저 해주어야함
                    distQueue[adjNode].push(u.first + W[u.second][adjNode]);
                    pq.push({ u.first + W[u.second][adjNode], adjNode });
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) { // K번째 경로 출력
        if (distQueue[i].size() == K) {
            cout << distQueue[i].top() << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
}