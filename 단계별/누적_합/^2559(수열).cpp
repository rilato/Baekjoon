// 틀린 풀이
// max 값을 초기화할 때 0이 아닌 음수로 해야 한다.
// sum의 값이 음수가 나올 수 있기 때문이다.
// 따라서 max도 음수로 설정한다.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, num;
	int sum = 0;
	int count = 0;
	int max = 0;
	vector <int> v;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);

		count++;
		sum += num;

		if (count == K) {
			if (sum >= max)
				max = sum;

			count--;
			sum -= v.front();
			v.erase(v.begin());
		}
	}

	cout << max;
}


// 맞은 풀이

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, num;
	int sum = 0;
	int count = 0;
	int max = -987654321;
	vector <int> v;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);

		count++;
		sum += num;

		if (count == K) {
			if (sum >= max)
				max = sum;

			count--;
			sum -= v.front();
			v.erase(v.begin());
		}
	}

	cout << max;
}