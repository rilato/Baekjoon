// ����� �� �κ��� ���� ���� �ƴ�, �� ���� �� ����� �͵��� �� �� �ִ��� ���� �����̴�.
// ���� �湮�ߴ� ���鿡 ���� �ٽ� visited[v] = false;�� �ǵ��� �ʿ䰡 ����.

// for each�� ������ ������.

#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> A;
vector <bool> visited;
void DFS(int v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, s, e;
	int cnt = 0;

	cin >> N >> M;

	// 1���� 1000�� ��� ���ؼ��� 0���� 1000������ �迭, �� 1001��ŭ�� �ʿ��ϴ�. ���� N�� �ִ밪 + 1 (1000 + 1)�� ���ش�.
	// 2���� �迭�� A �迭������, A �迭�� ���� ����� �������Ѵ�.
	A.resize(N + 1);
	visited = vector <bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		cin >> s >> e;

		A[s].push_back(e);
		A[e].push_back(s);
	}

	// ���� 1 ~ N���� �̹Ƿ�, �ش� ���鿡 ���� Ž���Ѵ�.
	for (int i = 1; i < N + 1; i++) {
		if (!visited[i]) {
			DFS(i);
			// ����� �� �κ��� ���� ���� �ƴ�, �� ���� �� ����� �͵��� �� �� �ִ��� ���� �����̹Ƿ�,
			// DFS�� ���� i�� ����� ��� �ֵ��� ���� �� ���� ī��Ʈ�Ѵ�.
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}

void DFS(int v) {
	// �ش� ��带 �湮�� ���� �ִٸ� ����
	if (visited[v])
		return;

	visited[v] = true;

	// ���� Ž������ ��忡 ����� �ֵ鿡 ���ؼ� for-each�� ���
	//for (int i : A[v]) {
	//	if (!visited[i]) {
	//		DFS(i);
	//	}
	//}

	// ���� Ž������ ��忡 ����� �ֵ鿡 ���ؼ� for�� ���
	for (int j = 0; j < A[v].size(); j++) {
		int i = A[v][j];

		if (!visited[i]) {
			DFS(i);
		}
	}
}