#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, x, y;
	vector<pair<int, int>> coordinate;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> x >> y;
		// x���� y���� �ݴ�� �־��ش�.
		coordinate.push_back({ y, x });
	}

	sort(coordinate.begin(), coordinate.end());

	// vector�� y���� ���� ����Ǿ������Ƿ�, x���� ���� ����ϱ� ���� second�� ���� ����.
	for (int i = 0; i < input; i++)
		cout << coordinate[i].second << ' ' << coordinate[i].first << '\n';
}