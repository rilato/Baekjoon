#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, num;
	int count = 0;
	vector <int> v;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	while (1) {
		// K가 0이면 동전의 개수를 모두 센 것이므로 탈출
		if (!K)
			break;

		// 동전의 몫을 더해나감
		count += K / v.back();
		// 동전의 나머지를 K에 저장
		K %= v.back();
		// 맨 뒤의 요소를 제거
		v.pop_back();
	}

	cout << count;
}