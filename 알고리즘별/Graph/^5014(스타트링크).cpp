#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int cnt = 0;
int dv[2];
int arr[1000001];
bool visited[1000001];
queue <int> q;

void BFS(int v);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> F >> S >> G >> U >> D;

	dv[0] = U;
	dv[1] = -D;

	BFS(S);

	if (visited[G])
		cout << arr[G];
	else
		cout << "use the stairs";
}

void BFS(int v) {
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		int v = q.front();

		q.pop();

		for (int i = 0; i < 2; i++) {
			int nv = v + dv[i];

			if (1 <= nv && nv <= F && !visited[nv]) {
				q.push(nv);
				visited[nv] = true;
				arr[nv] = arr[v] + 1;
			}
		}
	}
}