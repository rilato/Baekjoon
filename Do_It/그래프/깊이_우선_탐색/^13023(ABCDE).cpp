// Ư���� ģ���κ��� ���ӵ� 5���� ģ���� �ִ� �׷����� �ִ��� ã�� �����̴�.
// ���� �湮�ߴ� ���鿡 ���� �ٽ� visited[v] = false;�� �ǵ���

#include <iostream>
#include <vector>

using namespace std;

int N, M, a, b;
bool arrive = false;
vector <vector <int>> A;
vector <bool> visited;

void DFS(int v, int cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	A.resize(N);
	visited = vector <bool>(N, false);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		A[a].push_back(b);
		A[b].push_back(a);
	}

	// ģ���� ������ 0���� ����. N - 1�� ������ ģ��.
	// 0���� N - 1���� ���鼭 5���� ģ���� �����ؼ� �̾����� �ְ� �ִ��� Ȯ���ؾ� ��.
	for (int i = 0; i < N; i++) {
		// ���� Ž���� �����Ϸ��� i�� '��'�� �ش��ϹǷ�, ģ�� ���迡�� + 1�� ���ش�.
		// �� 5���� ģ�� ������, �� �� i�� �̹� 1�� ���ԵǾ��ִ�!!
		DFS(i, 1);

		// cnt == 5�� ������ �ְ� �ִٸ�, for�� Ż��
		if (arrive)
			break;
	}

	if (arrive)
		cout << 1;
	else
		cout << 0;

	return 0;
}

void DFS(int v, int cnt) {
	if (cnt == 5 || arrive) {
		arrive = true;
		return;
	}

	// visited �迭�� ���� ��� �湮 ���
	visited[v] = true;

	// ��������Ʈ ����̹Ƿ�, j = 0�� �� ���� ������ �˲� ������
	for (int j = 0; j < A[v].size(); j++) {
		int i = A[v][j];

		if (!visited[i]) {
			DFS(i, cnt + 1);
		}
	}

	// visited �迭�� ���� ��� �湮 ����
	// �ش� ���̱��� ���ٰ�, ������ �������� �ʾҴ� �ֵ��� �ٽ� �ǵ��� ���� �۾�
	// visited[v] = false; �� �������� ������, DFS �Լ��� ������ �湮�� ��带 ����� ä�� Ž���� �����ϰ� �ǹǷ� �����ϸ� �ȵ�!!
	visited[v] = false;
}