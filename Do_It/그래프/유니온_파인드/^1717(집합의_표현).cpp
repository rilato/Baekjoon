// 배열의 값으로, 각 인덱스의 대표 값을 넣는 방식인 유니온 파인드의 사용 법을 익힌다.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> parent;

void unionfunc(int a, int b);
int find(int a);
bool checkSame(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    parent.resize(N + 1);

    // 대표 노드를 자기 자신으로 초기화
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int question, a, b;

        cin >> question >> a >> b;

        // 입력으로 0이 들어오면, 합집합 연산을 실행하므로, 집합 합치기
        if (question == 0) {
            unionfunc(a, b);
        }

        // 입력으로 1이 들어오면, 같은 집합의 원소인지 확인하기
        else {
            if (checkSame(a, b)) {
                cout << "YES" << "\n";
            }

            else {
                cout << "NO" << "\n";
            }
        }
    }
}

// union 연산 : 바로 연결이 아닌 대표 노드끼리 연결하여 줌
void unionfunc(int a, int b) {
    // a, b의 대표 노드 찾기
    a = find(a);
    b = find(b);

    // 두 원소의 대표 노드끼리 연결
    if (a != b) {
        parent[b] = a;
    }
}

// find 연산 : 대표 노드를 찾아서 리턴
int find(int a) {
    // a가 대표 노드면 반환
    if (a == parent[a])
        return a;
    // 아니면 a의 대표 노드 값을 find(parent[a]) 값으로 저장 -> 재귀함수 형태
    else
        return parent[a] = find(parent[a]);	 // 재귀함수의 형태로 구현
}

bool checkSame(int a, int b) { // 두 원소가 같은 집합인지 확인
    a = find(a);
    b = find(b);

    if (a == b) {
        return true;
    }

    return false;
}