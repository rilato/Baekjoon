#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M, T;
int answer;
vector<int> v;  // 진실을 아는 사람들을 담은 벡터
vector<int> parent; // 사람들의 연관관계를 알기 위해, UnionFind를 저장할 벡터
vector<vector<int>> party;  // 파티 데이터

void unionfunc(int a, int b);
int find(int a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    parent.resize(N + 1);

    // Union Find 배열 초기화 (대표노드를 자신으로 초기화)
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    cin >> T;

    v.resize(T);

    // 진실을 아는 사람을 v벡터에 담기
    for (int i = 0; i < T; i++) {
        cin >> v[i];
    }

    party.resize(M);

    for (int i = 0; i < M; i++) {
        int parties;

        cin >> parties;

        for (int j = 0; j < parties; j++) {
            int temp;

            cin >> temp;

            party[i].push_back(temp);
        }
    }

    // 파티에 참여한 사람을 하나의 그룹으로 만들기
    for (int i = 0; i < M; i++) {
        int firstPeople = party[i][0];

        for (int j = 1; j < party[i].size(); j++) {
            // 각 파티에 참여한 사람을 1개의 그룹으로 만들기
            unionfunc(firstPeople, party[i][j]);
        }
    }

    // 각 파티에서 진실을 아는 사람과 같은 그룹에 있다면 과장할 수 없음
    for (int i = 0; i < M; i++) {
        bool isPossible = true;
        int firstPeople = party[i][0];  // 각 파티의 대표 노드

        for (int j = 0; j < T; j++) {
            // 각 파티의 대표 노드와 진실을 아는 사람의 대표 노드가 같다면 과장할 수 없음
            if (find(firstPeople) == find(v[j])) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            answer++;
        }
    }

    cout << answer;

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