// map을 sort하기 위해, vector의 pair로 변환하고, pair를 sort한다.

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string S;
map <string, int> m;

bool cmp(pair<string, int>& a, pair<string, int>& b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> S;

		if (S.size() >= M) {
			m[S]++;
		}
	}

	// 정렬을 위해 map을 vector로 변환
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << '\n';
	}

	return 0;
}

bool cmp(pair<string, int>& a, pair<string, int>& b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size()) {
			return a.first < b.first;
		}

		return a.first.size() > b.first.size();
	}

	return a.second > b.second;
}
