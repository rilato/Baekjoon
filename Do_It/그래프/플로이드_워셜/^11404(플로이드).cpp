// 플로이드 워셜 알고리즘
// "모든 도시"의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구해야 하므로, 플로이드 워셜 알고리즘을 사용한다.

#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

int N, M, A, B, C;
vector <vector <int>> dist;     // 최단 거리 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // 1번 도시부터 주어지므로, N + 1로 resize
    // N + 1로 행과 열을 모두 resize
    dist.resize(N + 1, vector <int> (N + 1));

    // 최단 거리 배열 초기화
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                // 플로이드 워셜 알고리즘에서, 나중에 경유지 연산할 때, 두 수의 합이 INT_MAX의 범위를 넘어갈 수 있으므로, INT_MAX의 절반 값 정도를 사용한다.
                dist[i][j] = 1000000001;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;

        // 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있으므로,
        // dist배열 값보다 더 작은 값이 들어올 때 업데이트
        if (dist[A][B] > C) {
            dist[A][B] = C;
        }
    }

    // 플로이드 워셜 알고리즘 수행
    // 중간 경유 노드 k
    for (int k = 1; k <= N; k++) {
        // 출발 노드 i
        for (int i = 1; i <= N; i++) {
            // 도착 노드 j
            for (int j = 1; j <= N; j++) {
                // 경유했을 때 dist가 더 작아진다면, 값 업데이트
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력해야 한다.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == 1000000001) {
                cout << "0 ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }

        cout << '\n';
    }

    return 0;
}
