// 배열의 값으로, 각 인덱스의 대표 값을 넣는 방식인 유니온 파인드의 사용 법을 익힌다.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> parent;

void unionfunc(int a, int b);
int find(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int dosi[201][201];
    int route[1001];

    cin >> N >> M;

    for (int i = 1; i <= N; i++) { 	// 도시 연결 데이터 저장
        for (int j = 1; j <= N; j++) {
            cin >> dosi[i][j];
        }
    }

    for (int i = 1; i <= M; i++) { 	//여행 도시 정보 저장
        cin >> route[i];
    }

    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) { 	// 대표 노드를 자기 자신으로 초기화
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) { 	// 인접행렬 탐색에서 도시가 연결되어 있으면 유니온 실행
        for (int j = 1; j <= N; j++) {
            if (dosi[i][j] == 1)
                unionfunc(i, j);
        }
    }

    // 여행 계획 도시들이 하나의 대표 도시로 연결되어 있는지 확인
    int index = find(route[1]);

    bool connect = true;

    for (int i = 2; i <= M; i++) {
        if (index != find(route[i])) {
            cout << "NO" << "\n";

            connect = false;

            break;
        }
    }

    if (connect)
        cout << "YES" << "\n";

    return 0;
}

void unionfunc(int a, int b) {	 // union 연산 : 바로 연결이 아닌 대표 노드끼리 연결하여 줌
    a = find(a);    // find연산을 통해, 변수 a와 b는 연결된 최상위 부분인 루트 노드를 가리키게 됨.
    b = find(b);

    if (a != b) {   // a != b일 때, 둘을 연결함.
        parent[b] = a;
    }
}

int find(int a) { 	// find 연산 : 대표 노드를 리턴
    if (a == parent[a]) // 인덱스와 값이 같으면 얘가 뿌리 노드임.
        return a;
    else
        return parent[a] = find(parent[a]); 	// 배열의 값(parent[a])을 인덱스(find의 인자)로 갖는 값 리턴
}