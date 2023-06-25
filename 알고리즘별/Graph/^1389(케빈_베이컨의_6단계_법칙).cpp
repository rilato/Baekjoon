// https://hagisilecoding.tistory.com/121
// 벡터와 배열의 조합을 이용한 풀이에 익숙해지도록 한다.
// 큐에 현재 탐색하는 값과, 카운트 값을 함께 넣어준다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> v[102];
int a, b;
int cnt = 0; // 시작 사람에서 목표 사람 까지의 단계 수

void bfs(int a, int b);

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        v[a].push_back(b); // 사람 관계는 양방향임.
        v[b].push_back(a);
    }

    int result = 987654321; // 케빈 베이컨의 수
    int num = 987654321; // 케빈 베이컨의 수에 해당하는 사람 번호

    for (int i = 1; i <= n; i++) { // 시작하는 사람
        int temp = 0; // 한 사람이 다른 사람까지 가는 단계

        for (int j = 1; j <= n; j++) { // 목표사람
            if (i == j) // 시작 사람과 목표 사람이 같은 경우 넘김
                continue;

            bfs(i, j);

            temp += cnt; // 각 목표 사람의 단계를 모두 합쳐 케빈 베이컨의 수를 구함

            cnt = 0; // 목표 사람의 단계 초기화
        }

        if (result > temp) { // 전의 케빈 베이컨의 수와 비교하여 더 작은 값을 저장
            result = temp;
            num = i;
        }

    }

    cout << num;

    return 0;
}

void bfs(int a, int b) {
    bool visit[102] = { 0, };
    queue<pair<int, int>> q;

    q.push({ a, 0 });
    visit[a] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int count = q.front().second;

        q.pop();

        if (x == b) {
            cnt = count;
            break;
        }

        for (int i = 0; i < v[x].size(); i++) {
            if (!visit[v[x][i]]) {
                q.push({ v[x][i], count + 1 });
                visit[v[x][i]] = true;
            }
        }
    }
}