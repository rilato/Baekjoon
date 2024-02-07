// vector의 type으로 <구조체>를 넣을 수 있다.
// 그 값으로 int, string 등을 넣을 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
	string name;
	int kor, eng, math;
};

// 함수는 구조체 뒤에 선언한다.
bool compare(student a, student b);

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	string input;

	cin >> N;

	// 벡터의 사이즈를 확실하게 정해줘야 벡터의 범위를 벗어나는 에러가 발생하지 않는다.
	vector<student> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i].name << '\n';
	}
}

bool compare(student a, student b) {
	if (a.kor == b.kor && a.math == b.math && a.eng == b.eng)
		return a.name < b.name;
	if (a.kor == b.kor && a.eng == b.eng)
		return a.math > b.math;
	if (a.kor == b.kor)
		return a.eng < b.eng;
	return a.kor > b.kor;
}