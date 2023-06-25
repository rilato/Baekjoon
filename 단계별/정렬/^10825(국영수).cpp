// vector�� type���� <����ü>�� ���� �� �ִ�.
// �� ������ int, string ���� ���� �� �ִ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
	string name;
	int kor, eng, math;
};

// �Լ��� ����ü �ڿ� �����Ѵ�.
bool compare(student a, student b);

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	string input;

	cin >> N;

	// ������ ����� Ȯ���ϰ� ������� ������ ������ ����� ������ �߻����� �ʴ´�.
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