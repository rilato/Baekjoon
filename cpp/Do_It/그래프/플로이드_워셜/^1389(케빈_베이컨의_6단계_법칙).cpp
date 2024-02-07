// 플로이드 워셜 알고리즘
// "모든 정점"의 경로에 대해 최단 경로를 구해야 하므로, 플로이드 워셜 알고리즘을 사용한다.

#include <iostream>
#include <vector>

using namespace std;

int N, M, A, B;
int answer = 1000000001;
vector <vector <int>> dist;     // 최단 거리 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dist.resize(N + 1, vector <int> (N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = 1000000001;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> A >> B;

        // 친구 관계라면 1로 설정
        dist[A][B] = 1;
        dist[B][A] = 1;
    }

    // 경유 노드 k
    for (int k = 1; k <= N; k++) {
        // 출발 노드 i
        for (int i = 1; i <= N; i++) {
            // 도착 노드 j
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int sum = 0;

        for (int j = 1; j <= N; j++) {
            sum += dist[i][j];
        }

        answer = min(answer, sum);
    }

    for (int i = 1; i <= N; i++) {
        int sum = 0;

        for (int j = 1; j <= N; j++) {
            sum += dist[i][j];
        }

        if (sum == answer) {
            cout << i;
            break;
        }
    }

    return 0;
}
