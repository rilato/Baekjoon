// 플로이드 워셜 알고리즘
// "모든 정점"의 경로 여부를 구해야 하므로, 플로이드 워셜 알고리즘을 사용한다.

#include <iostream>
#include <vector>

using namespace std;

int N;
vector <vector <int>> dist;     // 최단 거리 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dist.resize(N, vector <int> (N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dist[i][j];
        }
    }

    // 경유 노드 k
    for (int k = 0; k < N; k++) {
        // 출발 노드 i
        for (int i = 0; i < N; i++) {
            // 도착 노드 j
            for (int j = 0; j < N; j++) {
                // dist[i][k] == 1이고 dist[k][j] == 1이면 dist[i][j] = 1로 저장
                // 즉, 경유 노드 k를 거치는 모든 경로 중 하나라도 연결된 경로가 있다면, i와 j는 연결 노드로 취급
                if (dist[i][k] == 1 && dist[k][j] == 1) {
                    dist[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << dist[i][j] << " ";
        }

        cout << '\n';
    }

    return 0;
}
