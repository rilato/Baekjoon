// stable_sort가 sort보다 유용하게 쓰일 때가 있다.
// stable_sort는 pair에서 많이 쓰인다.

// 먼저 sort함수는 quick sort를 기반으로 구현되었다.
// sort 함수는 pair <int, int>에서 첫 번째 값을 기준으로 정렬해주지만, 두 번째 값이 어떤 순서로 정렬될지 예상할 수 없다.
// 즉 sort함수는 예측할 수 없는 불안정한 정렬이다.

// 반면 stable_sort함수는 merge sort를 기반으로 구현되었다.
// stable_sort는 첫 번째 값을 기준으로 정렬해주고, 두 번째 값은 정렬 전의 순서를 유지하도록 한다.
// 즉 stable_sort함수는 예측할 수 있는 안정한 정렬이다.
// stable_sort는 compare를 만들어줘야 하는데, compare함수는 단순하게 return a.first < b.first만 해주면 된다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, string>, pair<int, string>);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, age;
	string name;

	vector<pair<int, string>> ageNameVector;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> age >> name;
		ageNameVector.push_back({ age, name });
	}

	// compare를 통해 stable_sort를 안정화 시킨다. 
	stable_sort(ageNameVector.begin(), ageNameVector.end(), compare);

	for (int i = 0; i < input; i++)
		cout << ageNameVector[i].first << ' ' << ageNameVector[i].second << '\n';
}

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}




// stable sort와 pair를 쓰지 않은 풀이. 정렬 과정을 거치지 않아, 속도는 오히려 이게 더 빨랐다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, age;
	string name;

	// vector에서 다시 한번 배열을 만들어 이차원 배열을 만들었다.
	// 201은 행이 된다.
	vector<string> nameVector[201];

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> age >> name;
		// 이차원 배열이므로, 이렇게 값을 넣는다.
		// 넣어진 값은 열이 된다.
		nameVector[age].push_back(name);
	}

	for (int i = 0; i < 201; i++)
		// size()에서 j가 아닌 i다!!
		for (int j = 0; j < nameVector[i].size(); j++)
			cout << i << ' ' << nameVector[i][j] << '\n';
}