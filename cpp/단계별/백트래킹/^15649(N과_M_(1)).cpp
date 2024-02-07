// ��͸� �������� �ϴ� ��Ʈ��ŷ ����� �����Ѵ�
// vector�� for������ ����� ��, auto�� �̿��� ����� Ȯ���Ѵ�.

#include<iostream>
#include<vector>

using namespace std;

int N, M;
bool visited[9] = { 0, };
vector <int> v;

void backTracking();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	backTracking();
}

void backTracking() {
	if (v.size() == M) {
		for (auto& k : v)
			cout << k << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			backTracking();
			visited[i] = false;
			v.pop_back();
		}
	}
}

// �ٸ� Ǯ��

#include <iostream>

using namespace std;

int n, m;
int arr[10] = { 0, };
bool check[10] = { 0, };

void func(int k);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	// 0�� ° ���̺��� Ž��
	func(0);
}

void func(int k) {
	// ��ǥ�� ������ ���ϴ� ������ �����ߴٸ�
	if (k == m) {
		// k = 1�� ���� k = 2�� ���� ��� �� ���
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			// k��° ���̿��� ���ʴ�� ���� �־��
			arr[k] = i;
			// �湮�� ���� üũ ó��
			check[i] = 1;
			// 1��ŭ�� ���̸� �� ���� Ž��
			func(k + 1);
			// ��� �� return�� �����鼭, false�� �ٽ� �ٲ��ֱ�
			check[i] = 0;
		}
	}
}