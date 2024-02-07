// 15649�� ����� ��������, bool �迭�� ������� �ʴ´�.
// ��Ʈ��ŷ�� ������ �ľ��Ѵ�.

#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector <int> v;

void backTracking();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
		backTracking();
		v.pop_back();
	}
}

void backTracking() {
	if (v.size() == M) {
		for (auto& k : v)
			cout << k << " ";
		cout << "\n";
		return;
	}

	for (int i = v.back() + 1; i <= N; i++) {
		v.push_back(i);
		backTracking();
		v.pop_back();
	}
}


// �ٸ� Ǯ��

#include <iostream>

using namespace std;

int n, m;
int arr[10] = { 0, };
bool check[10] = { 0, };

void func(int num, int k);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	// 1���� Ž�� ����, 0�� ° ���̺��� Ž��
	func(1, 0);
}

void func(int num, int k) {
	// ��ǥ�� ������ ���ϴ� ������ �����ߴٸ�
	if (k == m) {
		// k = 1�� ���� k = 2�� ���� ��� �� ���
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = num; i <= n; i++) {
		if (!check[i]) {
			// k��° ���̿��� ���ʴ�� ���� �־��
			arr[k] = i;
			// �湮�� ���� üũ ó��
			check[i] = 1;
			// k��° ������ ������ �ϳ� �� ū ������ �����ϹǷ�, i + 1�� �ְ�, 1��ŭ�� ���̸� �� ���� Ž��
			// for���� index ���� ����Լ��� ���ڷ� �Ѱ������ν� �̹� ã�� ������ �ٽ� ���� �ʵ��� ��
			func(i + 1, k + 1);
			// ��� �� return�� �����鼭, false�� �ٽ� �ٲ��ֱ�
			check[i] = 0;
		}
	}
}