// vector의 type으로 <구조체>를 넣을 수 있다.
// 그 값으로 int, string 등을 넣을 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Olympiad {
	int nation, number, score;
};

bool compare(Olympiad a, Olympiad b);

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int count = 0;
	int check = 0;
	int j = 0;

	cin >> N;

	vector<Olympiad> v(N);
	vector<Olympiad> ans(3);

	for (int i = 0; i < N; i++) {
		cin >> v[i].nation >> v[i].number >> v[i].score;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N - 1; i++) {
		if (v[i].nation == check && count == 2)
			continue;

		if (j == 3)
			break;

		ans[j].nation = v[i].nation;
		ans[j].number = v[i].number;
		ans[j].score = v[i].score;
		j++;

		if (v[i].nation == v[i + 1].nation) {
			check = v[i].nation;
			++count;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << ans[i].nation << ' ' << ans[i].number << '\n';
	}
}

bool compare(Olympiad a, Olympiad b) {
	return a.score > b.score;
}


// 다른 풀이