// 벨만포드 알고리즘

#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

int N, S, E, M, A, B, C;
vector <tuple <int, int, int>> edges;    // 에지 정보 저장
vector <long> dist, money;     // 최단 거리 배열, 도시마다 벌 수 있는 돈 저장 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S >> E >> M;

    // 0번 도시부터 주어지므로, N + 1이 아닌, N만큼 사이즈 지정
    dist.resize(N);
    money.resize(N);

    // 최단 거리 배열 초기화
    for (int i = 0; i < N; i++) {
        dist[i] = LONG_MIN;
    }

    for (int i = 0; i < M; i++) {
        // A는 출발 도시, B는 도착 도시, C는 교통비
        cin >> A >> B >> C;

        // 에지 정보 저장. tuple은 make_tuple 혹은 {}를 통해 삽입
        edges.push_back({ A, B, C });
    }

    for (int i = 0; i < N; i++) {
        cin >> money[i];
    }

    // 벨만 포드 알고리즘 수행
    // Start 지점 도시에서 출발해서 나머지 도시로 가는 비용을 구해야 하므로, 인덱스는 S, 값은 money[S]
    dist[S] = money[S];

    // 양수 사이클이 전파되도록 충분히 큰 수로 반복 (N + 50)
    for (int i = 0; i <= N + 50; i++) {
        // 에지 개수만큼 반복 (전체 간선 E개를 하나씩 확인)
        for (int j = 0; j < M; j++) {
            // 현재 에지 데이터 가져오기
            tuple <int, int, int> medge = edges[j];

            int start = get<0>(medge);
            int end = get<1>(medge);
            int price = get<2>(medge);

            // 시작 노드가 미방문 노드이면 continue
            if (dist[start] == LONG_MIN) {
                continue;
            }

            // 시작 노드가 양수 사이클에 연결된 노드라면, 종료 노드도 연결 노드로 갱신
            else if (dist[start] == LONG_MAX) {
                dist[end] = LONG_MAX;
            }

            // 더 많은 돈을 벌 수 있는 새로운 경로를 발견하면 새로운 경로 값으로 갱신
            if (dist[end] < dist[start] + money[end] - price) {
                dist[end] = dist[start] + money[end] - price;

                // N - 1번 반복 이후 갱신되는 종료 노드는 양수 사이클 연결 노드로 변경
                if (i >= N - 1) {
                    dist[end] = LONG_MAX;
                }
            }
        }
    }

    // 도착 불가능
    if (dist[E] == LONG_MIN) {
        cout << "gg";
    }
    // 양수 사이클 연결
    else if (dist[E] == LONG_MAX) {
        cout << "Gee";
    }
    // 그 이외의 경우
    else {
        cout << dist[E];
    }

    return 0;
}
