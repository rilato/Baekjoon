// ��Ʈ��ŷ �� ������ �޸� ��Ʈ��ŷ�� ��� �ذ��ϴ��� Ȯ���� �ʿ䰡 �ִ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
char c;
vector <char> v;
vector <char> ans;
bool visited[16];

void Backtracking(int cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> c;
		v.push_back(c);
	}

	sort(v.begin(), v.end());

	Backtracking(0);
}

void Backtracking(int cnt) {
	if (cnt == L) {
		// �� ���� ������ �� ���� ������ ��󳻱� ���� �κ�
		int m = 0;
		int z = 0;

		for (int i = 0; i < L; i++) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				m++;
			else
				z++;
		}

		// ������ ���ų� ������ �� �� ������ �͵��� �Ÿ�
		if (m < 1 || z < 2)
			return;

		for (int i = 0; i < L; i++) {
			cout << ans[i];
		}

		cout << '\n';
		return;
	}

	for (int i = 0; i < C; i++) {
		// ans ���Ͱ� ������� �ʰ�, �� �ڿ� �ִ� ���ڰ� ���� Ž���ϰ� �ִ� ���ں��� ���ĺ� ���� �� �ڿ� �ִ� ���, �ǳ� ��
		if (!ans.empty() && ans.back() > v[i])
			continue;

		if (!visited[i]) {
			visited[i] = true;
			ans.push_back(v[i]);
			Backtracking(cnt + 1);
			ans.pop_back();
			visited[i] = false;
		}
	}
}