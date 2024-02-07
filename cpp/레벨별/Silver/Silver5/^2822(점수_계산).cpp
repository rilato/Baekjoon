// pair의 사용 방법을 익힌다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector <pair <int, int>> v;
	int arr[5] = { 0, };
	int num;
	int ans = 0;


	for (int i = 0; i < 8; i++) {
		cin >> num;

		v.push_back({ num, i + 1 });
	}

	// pair의 앞에 수를 기준으로 정렬,
	// greater를 쓰면 내림차순 정렬
	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < 5; i++) {
		arr[i] = v[i].second;
		ans += v[i].first;
	}

	sort(arr, arr + 5);

	cout << ans << '\n';

	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
}