// 백트래킹 중 조건이 달린 백트래킹을 어떻게 해결하는지 확인할 필요가 있다.

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
		// 한 개의 모음과 두 개의 자음을 골라내기 위한 부분
		int m = 0;
		int z = 0;

		for (int i = 0; i < L; i++) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				m++;
			else
				z++;
		}

		// 모음이 없거나 자음이 한 개 이하인 것들은 거름
		if (m < 1 || z < 2)
			return;

		for (int i = 0; i < L; i++) {
			cout << ans[i];
		}

		cout << '\n';
		return;
	}

	for (int i = 0; i < C; i++) {
		// ans 벡터가 비어있지 않고, 맨 뒤에 있는 문자가 현재 탐색하고 있는 문자보다 알파벳 순서 상 뒤에 있는 경우, 건너 뜀
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