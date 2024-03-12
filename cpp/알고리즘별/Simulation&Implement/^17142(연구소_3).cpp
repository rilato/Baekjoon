// 기존 코드에서 map[nr][nc] != 1을 할 경우, map이 1을 넘는 순간 계속 값이 푸시되므로, map의 값들이 계속 갱신되며 무한 루프에 빠진다.
// 이를 해결하기 위해, 출발점을 제외하고 모두 값을 -1로 초기화한다.
// 또한 최단 시간을 구하며 map을 갱신해 나가는 문제의 경우, if (!visited[nr][nc])의 경우를 체크하지 않는다. 먼저 도착한 놈이 무조건 더 빠른 놈이기 때문이고, 저 제약이 있으면, 이미 다른 놈이 지나간 자리는 못 지나가기 때문.

// 틀린 풀이
// 반례 : https://www.acmicpc.net/board/view/98175 참고

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int minimum = INT_MAX;	// 최종적으로 구할 최소 값이므로, 여기서 선언해야 함
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
vector <vector <int>> v;
vector <pair <int, int>> virus;
vector <bool> visited;
vector <int> combination;
vector <bool> flag;

void Backtracking(int depth, int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	v.resize(N, vector <int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];

			if (v[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}

	//cout << '\n';

	visited.resize(virus.size());

	Backtracking(0, 0);

	for (int i = 0; i < flag.size(); i++) {
		if (flag[i]) {
			cout << minimum - 2;	// 바이러스의 출발점인 2에서 숫자를 더해나갔으므로, 최종적으로 2를 빼주어야 함.

			return 0;
		}
	}

	cout << -1;

	return 0;
}

void Backtracking(int depth, int idx) {
	if (depth == M) {
		queue <pair <int, int>> q;
		vector <vector <int>> map = v;
		vector <vector <bool>> visit;
		int maximum = 0;	// 최대 값은 매번 달라지므로, 여기서 선언해야 함

		visit.resize(N, vector <bool>(N));

		// 구한 조합대로, 인덱스를 큐에 넣기
		for (int i = 0; i < combination.size(); i++) {
			int idx = combination[i];
			int r = virus[idx].first;
			int c = virus[idx].second;

			// cout << "idx : " << idx << '\n';
			// cout << "r : " << r << ", c : " << c << '\n';

			q.push({ r, c });
		}

		while (!q.empty()) {
			int row = q.front().first;
			int col = q.front().second;
			
			visit[row][col] = true;

			// cout << "row : " << row << ", col : " << col << '\n';

			q.pop();

			// 바이러스를 퍼뜨리며, 가장 오래 걸린 시간 구하기 <- 바이러스 완전 생성이 불가능한 경우가 있으므로, 여기서 계산하면 안됨!!
			// maximum = max(maximum, map[row][col]);

			for (int i = 0; i < 4; i++) {
				int nr = row + dr[i];
				int nc = col + dc[i];

				if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
					continue;
				}

        // 반례 발생 지점!
				if (map[nr][nc] == 0) {
					map[nr][nc] = map[row][col] + 1;
					q.push({ nr, nc });
				}
			}
		}

		bool tempFlag = true;
		// 바이러스를 퍼뜨리는 데 불가능한 경로가 있는지 찾기 + 가능한 경로가 있다면, 최대값 찾기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v[i][j] == 0 && visit[i][j] == false) {
					tempFlag = false;
				}

				// 최대 값은 map에 기록했기 때문에, v[i][j]가 아닌 map[i][j]를 살펴야 함
				maximum = max(maximum, map[i][j]);
			}
		}

		//cout << "flag : " << tempFlag << '\n';

		// 바이러스를 모두 퍼뜨릴 수 있을 경우에만 minimum 값 갱신하기
		if (tempFlag) {
			// 가장 오래 걸린 시간들 중, 가장 적게 걸리는 시간 구하기
			minimum = min(minimum, maximum);
		}

		flag.push_back(tempFlag);

		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << map[i][j] << " ";
		//	}
		//	cout << '\n';
		//}

		//cout << "maximum : " << maximum << ", minimum : " << minimum << '\n' << '\n';

		return;
	}

	// 조합을 찾아야 하므로, i = 0이 아닌, idx부터 시작한다!
	for (int i = idx; i < virus.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			combination.push_back(i);
			Backtracking(depth + 1, i + 1);
			combination.pop_back();
			visited[i] = false;
		}
	}
}



// 맞은 풀이

// 감염될만한 장소가 모두 감염되었다면, 탈출하는 코드와
// 벽을 제외하고 모두 -1로 설정한 뒤 갱신해 나가는 코드를 생각하지 못했음

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int minimum = INT_MAX;	// 최종적으로 구할 최소 값이므로, 여기서 선언해야 함
int empty_place = 0;	// 바이러스가 없고, 벽이 없는 장소
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
vector <vector <int>> v;
vector <pair <int, int>> virus;
vector <bool> visited;
vector <int> combination;
vector <bool> flag;

void Backtracking(int depth, int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	v.resize(N, vector <int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];

			if (v[i][j] == 2) {
				virus.push_back({ i, j });
			}

			if (v[i][j] == 0) {
				empty_place++;
			}
		}
	}

	//cout << '\n';

	visited.resize(virus.size());

	Backtracking(0, 0);

	for (int i = 0; i < flag.size(); i++) {
		if (flag[i]) {
			cout << minimum;

			return 0;
		}
	}

	cout << -1;

	return 0;
}

void Backtracking(int depth, int idx) {
	if (depth == M) {
		queue <pair <int, int>> q;
		vector <vector <int>> map;
		int infect_place = 0;	// 감염된 장소의 개수
		int maximum = 0;	// 최대 값은 매번 달라지므로, 여기서 선언해야 함

		map.resize(N, vector <int>(N));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = -1;
			}
		}

		// 구한 조합대로, 인덱스를 큐에 넣기
		for (int i = 0; i < combination.size(); i++) {
			int idx = combination[i];
			int r = virus[idx].first;
			int c = virus[idx].second;

			//cout << "idx : " << idx << '\n';
			//cout << "r : " << r << ", c : " << c << '\n';

			q.push({ r, c });

			// 출발 지점만 0으로 세팅
			map[r][c] = 0;
		}

		while (!q.empty()) {
			int row = q.front().first;
			int col = q.front().second;

			// cout << "row : " << row << ", col : " << col << '\n';

			q.pop();

			// 감염될만한 장소가 모두 감염되었다면, 탈출
			if (infect_place == empty_place) {
				break;
			}

			// 바이러스를 퍼뜨리며, 가장 오래 걸린 시간 구하기 <- 바이러스 완전 생성이 불가능한 경우가 있으므로, 여기서 계산하면 안됨!!
			// maximum = max(maximum, map[row][col]);

			for (int i = 0; i < 4; i++) {
				int nr = row + dr[i];
				int nc = col + dc[i];

				if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
					continue;
				}

				// 벽을 제외하고, 바이러스 (숫자가 2인 곳) 위를 지나갈 수도 있다.
				// 따라서 벽인 경우 : map[nr][nc] == 1를 제외하고,
				// 값이 아직 갱신 안된 곳 : map[nr][nc] == -1이어야 한다.
				if (v[nr][nc] != 1 && map[nr][nc] == -1) {
					map[nr][nc] = map[row][col] + 1;
					q.push({ nr, nc });

					// 새롭게 감염된 곳 개수 세기
					if (v[nr][nc] == 0) {
						infect_place++;
					}
				}
			}
		}

		bool tempFlag = true;
		// 바이러스를 퍼뜨리는 데 불가능한 경로가 있는지 찾기 + 가능한 경로가 있다면, 최대값 찾기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v[i][j] == 0 && map[i][j] == -1) {
					tempFlag = false;
				}

				// 최대 값은 map에 기록했기 때문에, v[i][j]가 아닌 map[i][j]를 살펴야 함
				maximum = max(maximum, map[i][j]);
			}
		}

		// cout << "flag : " << tempFlag << '\n';

		// 바이러스를 모두 퍼뜨릴 수 있을 경우에만 minimum 값 갱신하기
		if (tempFlag) {
			// 가장 오래 걸린 시간들 중, 가장 적게 걸리는 시간 구하기
			minimum = min(minimum, maximum);
		}

		flag.push_back(tempFlag);

		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << map[i][j] << " ";
		//	}
		//	cout << '\n';
		//}

		//cout << "maximum : " << maximum << ", minimum : " << minimum << '\n' << '\n';

		return;
	}

	// 조합을 찾아야 하므로, i = 0이 아닌, idx부터 시작한다!
	for (int i = idx; i < virus.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			combination.push_back(i);
			Backtracking(depth + 1, i + 1);
			combination.pop_back();
			visited[i] = false;
		}
	}
}
