// 0부터 N까지의 노드에 주어진 질량을 각각 구하여 출력한다.


#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> A[10]; // 연결된 애, 비율 p q를 넣기 위해 튜플 사용
long long lcm;
bool visited[10];
long long D[10];    // 각 노드 값 저장 배열

long long gcd(long long a, long long b);
void DFS(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    lcm = 1;

    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;

        cin >> a >> b >> p >> q;

        // 인접 리스트에 배열에 해당 에지 정보를 저장
        A[a].push_back(make_tuple(b, p, q));
        A[b].push_back(make_tuple(a, q, p));

        lcm *= (p * q / gcd(p, q)); // 모든 p q에 대해 최소공배수 구하기.
    }

    // 0번 노드에 최소 공배수 저장
    D[0] = lcm;

    DFS(0);

    long long mgcd = D[0];

    // DFS를 통해 업데이트된 배열 D 값들 사이의 최대 공약수 계산
    for (int i = 1; i < N; i++) {
        mgcd = gcd(mgcd, D[i]);
    }

    // 배열 D의 각 값을 최대 공약수로 나누어서 정답 출력
    for (int i = 0; i < N; i++) {
        cout << D[i] / mgcd << ' ';
    }
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void DFS(int node) { // DFS구현
    visited[node] = true;

    //for (tuple<int, int, int> i : A[node]) {
    //    int next = get<0>(i);
    //
    //    if (!visited[next]) {
    //        D[next] = D[node] * get<2>(i) / get<1>(i); //주어진 비율로 다음 노드 값 업데이트
    //        DFS(next);
    //    }
    //}

    for (int j = 0; j < A[node].size(); j++) {
        tuple<int, int, int> i = A[node][j];


        // `get<0> (i)`는 튜플 `i`의 첫 번째 요소를 가져오는 것을 의미한다.
        // `i`는 `tuple<int, int, int > ` 형식의 튜플이므로, `get<0 > (i)`는 첫 번째 `int` 요소를 반환한다.
        // 따라서 `int next = get<0>(i); `는 튜플 `i`의 첫 번째 요소를 `next` 변수에 할당하는 것을 의미한다.
        // 이 코드는 주어진 튜플에서 첫 번째 요소를 추출하여 다음 노드를 나타내는 변수 `next`에 할당하는 역할을 한다.
        int next = get<0>(i);

        // 현재 노드의 연결 노드 중 방문하지 않은 노드에 대해
        if (!visited[next]) {
            D[next] = D[node] * get<2>(i) / get<1>(i);  // 다음 노드값 = 현재 노드값 * 비율로 갱신하기
            DFS(next);
        }
    }

}