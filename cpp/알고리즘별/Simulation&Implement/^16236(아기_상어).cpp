// 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
// 위의 조건을 만족하기 위해, BFS를 통해 최소 거리를 찾은 후
// 최소 거리를 만족하는 애를 위쪽부터 탐색한다.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, rowIdx, colIdx;
int answer = 0;
int eat = 0;
int shark = 2;
int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };
vector <vector <int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N, vector <int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];

            if (v[i][j] == 9) {
                rowIdx = i;
                colIdx = j;
            }
        }
    }

    while (1) {
        vector <vector <bool>> visited;
        vector <vector <int>> map;
        queue <pair <int, int>> q;
        vector <pair <int, int>> idx;
        int gap = INT_MAX;
        bool flag = false;
        bool loopFlag = false;

        visited.resize(N, vector <bool>(N));
        map.resize(N, vector <int>(N));

        //cout << "Before\n";
        //for (int i = 0; i < N; i++) {
        //    for (int j = 0; j < N; j++) {
        //        cout << v[i][j] << " ";
        //    }
        //    cout << '\n';
        //}
        //cout << "shark : " << shark << '\n';

        // 거리 계산
        // 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
        q.push({ rowIdx, colIdx });
        v[rowIdx][colIdx] = 0;
        visited[rowIdx][colIdx] = true;

        // 최소가 되는 gap 찾기
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            //cout << "r : " << r << ", c : " << c << ", t : " << t << '\n';

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
                    continue;
                }

                if (v[nr][nc] != 0 && v[nr][nc] < shark && !visited[nr][nc]) {
                    flag = true;
                    map[nr][nc] = map[r][c] + 1;
                    visited[nr][nc] = true;

                    if (map[nr][nc] < gap) {
                        gap = map[nr][nc];
                    }
                }

                else if (!visited[nr][nc] && (v[nr][nc] == 0 || v[nr][nc] == shark)) {
                    map[nr][nc] = map[r][c] + 1;
                    visited[nr][nc] = true;
                    q.push({ nr, nc });
                }
            }
        }

        // 조건에 만족하는 애가 없다면 탈출
        if (!flag) {
            break;
        }

        // gap과 일치하는 { row, col } 찾기
        // 1 2 3
        // 4 5 6
        // 7 8 9 순으로 탐색하므로, gap이 찾아진 순간 탐색 조건에 맞는 것.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (v[i][j] != 0 && v[i][j] < shark && gap == map[i][j]) {
                    v[i][j] = 0;
                    eat++;

                    answer += map[i][j];

                    rowIdx = i;
                    colIdx = j;

                    if (eat == shark) {
                        shark++;
                        eat = 0;
                    }

                    loopFlag = true;

                    break;
                }
            }

            if (loopFlag) {
                break;
            }
        }

        /*cout << "After\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << v[i][j] << " ";
            }
            cout << '\n';
        }

        cout << "answer : " << answer << '\n';*/
    }

    cout << answer;

    return 0;
}
