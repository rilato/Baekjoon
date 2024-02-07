// 15649번이 백트래킹을 통한 순열 구하기였다면, 이번 문제는 백트래킹을 통한 조합 구하기라고 할 수 있다.
// for문의 index값을 함께 재귀함수의 인자로 넘겨주면 앞에서 이미 찾은 조합은 다시 뽑지 않도록 만들 수 있다.

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector <int> v;
vector <bool> visited;

void Backtracking(int num, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v.resize(M);
    visited.resize(N + 1);

    Backtracking(1, 0);

    return 0;
}

void Backtracking(int num, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << v[i] << ' ';
        }

        cout << '\n';

        return;
    }

    for (int i = num; i <= N; i++) {
        if (!visited[i]) {
            // depth에 숫자 넣기
            v[depth] = i;
            // 방문한 곳은 체크 처리
            visited[i] = true;
            // depth보다 1만큼의 깊이를 더 들어가서 탐색
            // for문의 index 값을 재귀함수의 인자로 넘겨줌으로써 이미 찾은 조합은 다시 뽑지 않도록 함
            Backtracking(i + 1, depth + 1);
            // 출력 후 return을 만나면서, false로 다시 바꿔주기
            visited[i] = false;
        }
    }
}