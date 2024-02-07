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
		// x값과 y값을 반대로 넣어준다.
		coordinate.push_back({ y, x });
	}

	sort(coordinate.begin(), coordinate.end());

	// vector에 y값이 먼저 저장되어있으므로, x값을 먼저 출력하기 위해 second를 먼저 쓴다.
	for (int i = 0; i < input; i++)
		cout << coordinate[i].second << ' ' << coordinate[i].first << '\n';
}