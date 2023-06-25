// stable_sort�� sort���� �����ϰ� ���� ���� �ִ�.
// stable_sort�� pair���� ���� ���δ�.

// ���� sort�Լ��� quick sort�� ������� �����Ǿ���.
// sort �Լ��� pair <int, int>���� ù ��° ���� �������� ������������, �� ��° ���� � ������ ���ĵ��� ������ �� ����.
// �� sort�Լ��� ������ �� ���� �Ҿ����� �����̴�.

// �ݸ� stable_sort�Լ��� merge sort�� ������� �����Ǿ���.
// stable_sort�� ù ��° ���� �������� �������ְ�, �� ��° ���� ���� ���� ������ �����ϵ��� �Ѵ�.
// �� stable_sort�Լ��� ������ �� �ִ� ������ �����̴�.
// stable_sort�� compare�� �������� �ϴµ�, compare�Լ��� �ܼ��ϰ� return a.first < b.first�� ���ָ� �ȴ�.

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

	// compare�� ���� stable_sort�� ����ȭ ��Ų��. 
	stable_sort(ageNameVector.begin(), ageNameVector.end(), compare);

	for (int i = 0; i < input; i++)
		cout << ageNameVector[i].first << ' ' << ageNameVector[i].second << '\n';
}

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}




// stable sort�� pair�� ���� ���� Ǯ��. ���� ������ ��ġ�� �ʾ�, �ӵ��� ������ �̰� �� ������.

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

	// vector���� �ٽ� �ѹ� �迭�� ����� ������ �迭�� �������.
	// 201�� ���� �ȴ�.
	vector<string> nameVector[201];

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> age >> name;
		// ������ �迭�̹Ƿ�, �̷��� ���� �ִ´�.
		// �־��� ���� ���� �ȴ�.
		nameVector[age].push_back(name);
	}

	for (int i = 0; i < 201; i++)
		// size()���� j�� �ƴ� i��!!
		for (int j = 0; j < nameVector[i].size(); j++)
			cout << i << ' ' << nameVector[i][j] << '\n';
}