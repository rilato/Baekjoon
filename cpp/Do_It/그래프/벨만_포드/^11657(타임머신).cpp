// 벨만포드 알고리즘

#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

int N, M, A, B, C;
typedef tuple <int, int, int> edge;
vector <long> dist;     // 최단 거리 배열
vector <edge> edges;    // 에지 정보 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dist.resize(N + 1);

    // 최단 거리 배열 초기화
    for (int i = 0; i <= N; i++) {
        dist[i] = LONG_MAX;
    }

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;

        // 에지 정보 저장. tuple은 make_tuple 혹은 {}를 통해 삽입
        edges.push_back({ A, B, C });
    }

    // 벨만 포드 알고리즘 수행
    // 1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하므로, 인덱스는 1, 값은 0
    dist[1] = 0;

    // 1. 최단 거리 테이블 작성
    // N보다 하나 작은 수만큼 반복 (N - 1만큼 반복)
    for (int i = 1; i < N; i++) {
        // 에지 개수만큼 반복 (전체 간선 E개를 하나씩 확인)
        for (int j = 0; j < M; j++) {
            // 현재 에지 데이터 가져오기
            edge medge = edges[j];

            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);

            // 출발 노드가 무한대가 아니고, 더 작은 최단거리가 있는 경우 갱신
            if (dist[start] != LONG_MAX && dist[start] + time < dist[end]) {
                dist[end] = dist[start] + time;
            }
        }
    }

    // 2. 최단 거리 테이블을 한 번 더 돌면서, 음수 순환 간선이 발생하는지 체크. dist가 갱신된다면, 음수 간선이 존재한다는 것.
    bool mCycle = false;

    // 음수 cycle 확인
    for (int i = 0; i < M; i++) {
        // 현재 에지 데이터 가져오기
        edge medge = edges[i];

        int start = get<0>(medge);
        int end = get<1>(medge);
        int time = get<2>(medge);

        // 업데이트가 가능하다는 것은, 음수 사이클이 존재한다는 것
        if (dist[start] != LONG_MAX && dist[start] + time < dist[end]) {
            mCycle = true;
        }
    }

    if (!mCycle) { // 음의 cycle이 없는 경우
        for (int i = 2; i <= N; i++) {
            // 거리 배열에 무한대 값이 있는 경우, -1 출력
            if (dist[i] == LONG_MAX)
                cout << -1 << "\n";
            else
                cout << dist[i] << "\n";
        }
    }
    else { // 음의 cycle이 있는 경우
        cout << -1 << "\n";
    }

    return 0;
}
