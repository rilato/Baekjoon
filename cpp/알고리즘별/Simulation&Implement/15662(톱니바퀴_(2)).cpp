#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, K, tnum, direction;
string S;
int cnt = 0;
int dx[2] = { -1, 1 };
vector <vector <int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    v.resize(T + 1, vector <int>(8));

    for (int i = 1; i <= T; i++) {
        cin >> S;

        for (int j = 0; j < S.size(); j++) {
            v[i][j] = S[j] - '0';
        }
    }

    // 2번 인덱스는 우측, 6번 인덱스는 좌측
    // 2번과 6번이 맞닿음

    cin >> K;

    while (K--) {
        cin >> tnum >> direction;

        // 회전해야할 톱니바퀴와 회전 방향을 저장
        vector <pair<int, int>> tmp;
        queue <pair <int, int>> q;
        vector <bool> visited(T + 1);
        // leftFlag가 true인 경우에만 왼쪽 톱니바퀴가 회전 가능
        bool leftFlag = true;
        // rightFlag가 true인 경우에만 오른쪽 톱니바퀴가 회전 가능
        bool rightFlag = true;

        q.push({ tnum, direction });
        visited[tnum] = true;
        tmp.push_back({ tnum, direction });

        while (!q.empty()) {
            int now = q.front().first;
            int nowDirection = q.front().second;
            q.pop();

            for (int i = 0; i < 2; i++) {
                int next = now + dx[i];
                int nextDirection = (nowDirection == 1 ? -1 : 1);

                // 범위 넘어가면 탐색 안함
                if (next < 1 || next > T) {
                    continue;
                }

                if (!visited[next]) {
                    // 일단 방문한 곳에 대해 방문처리
                    visited[next] = true;

                    // 다음 방문할 곳이 더 크다는 것은, 다음 방문할 곳이 기존보다 우측에 있음을 의미함
                    // 따라서 기존의 우측 톱니바퀴와 다음의 좌측 톱니바퀴를 비교해야 함
                    if (rightFlag && next > now && v[now][2] != v[next][6]) {
                        q.push({ next, nextDirection });
                        tmp.push_back({ next, nextDirection });
                    }
                    // 다음 방문할 곳이 더 작다는 것은, 다음 방문할 곳이 기존보다 좌측에 있음을 의미함
                    // 따라서 기존의 좌측 톱니바퀴와 다음의 우측 톱니바퀴를 비교해야 함
                    else if (leftFlag && next < now && v[now][6] != v[next][2]) {
                        q.push({ next, nextDirection });
                        tmp.push_back({ next, nextDirection });
                    }
                    // 그 이외의 경우는 다음 방문할 곳에서 톱니바퀴의 변화가 없음을 의미
                    else {
                        if (next > now) {
                            rightFlag = false;
                        }
                        else {
                            leftFlag = false;
                        }
                        q.push({ next, nowDirection });
                    }
                }
            }
        }

        // 돌려야할 톱니바퀴를 찾아 돌리기
        for (int i = 0; i < tmp.size(); i++) {
            int t = tmp[i].first;
            int d = tmp[i].second;

            // 시계 방향 회전
            if (d == 1) {
                int temp = v[t][7];

                for (int j = 6; j >= 0; j--) {
                    v[t][j + 1] = v[t][j];
                }

                v[t][0] = temp;
            }
            // 반시계 방향 회전
            if (d == -1) {
                int temp = v[t][0];

                for (int j = 0; j <= 6; j++) {
                    v[t][j] = v[t][j + 1];
                }

                v[t][7] = temp;
            }
        }
    }

    // S극 개수 찾기
    for (int i = 1; i <= T; i++) {
        if (v[i][0] == 1) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}