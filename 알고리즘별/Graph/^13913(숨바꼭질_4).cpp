#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
vector <bool> visited;
vector <int> parent;        // 현재 바라보는 index의 부모 경로는 index의 값, index의 값의 자식경로는 index
// parent 배열은 최단 시간을 구하는 이 문제에서, 한 번 적혀진 값이 다른 값으로 오버라이딩 되지 않는 것 같다.
queue <pair<int, int>> q;   // {위치, 시간} 저장
vector <int> answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    visited.resize(100001);
    parent.resize(100001);

    q.push({ N, 0 });
    visited[N] = true;

    while (!q.empty()) {
        int now = q.front().first;
        int time = q.front().second;

        q.pop();

        if (now == K) {
            int index = now;

            while (index != N) {
                answer.push_back(index);    // 현재 보고 있는 경로 넣기
                index = parent[index];      // index = 부모 경로로 설정
            }

            // 맨 처음 수 넣기
            answer.push_back(N);

            cout << time << '\n';

            break;
        }

        if (now - 1 >= 0 && !visited[now - 1]) {
            visited[now - 1] = true;
            q.push({ now - 1, time + 1 });
            parent[now - 1] = now;
        }
        if (now + 1 <= 100000 && !visited[now + 1]) {
            visited[now + 1] = true;
            q.push({ now + 1, time + 1 });
            parent[now + 1] = now;
        }
        if (now * 2 <= 100000 && !visited[now * 2]) {
            visited[now * 2] = true;
            q.push({ now * 2, time + 1 });
            parent[now * 2] = now;
        }
    }

    for (int i = answer.size() - 1; i >= 0; i--) {
        cout << answer[i] << " ";
    }

    return 0;
}