#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
string S;
int answer = 0;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
vector <vector <int>> v;
vector <vector <bool>> visited;
vector <int> ans;

int BFS(int row, int col);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N, vector <int>(N));
    visited.resize(N, vector <bool>(N));

    for (int i = 0; i < N; i++) {
        cin >> S;

        for (int j = 0; j < N; j++) {
            v[i][j] = S[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j] == 1 && !visited[i][j]) {
                int cnt = BFS(i, j);
                ans.push_back(cnt);
                answer++;
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << answer << '\n';

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}

int BFS(int row, int col) {
    int count = 0;
    queue <pair <int, int>> q;

    q.push({ row, col });
    visited[row][col] = true;
    count++;    // 현재 방문한 애 카운트

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visited[nr][nc] && v[nr][nc] == 1) {
                visited[nr][nc] = true;
                q.push({ nr, nc });
                count++;
            }
        }
    }

    return count;
}