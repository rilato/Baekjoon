#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt = 0;
vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int left = 0;
	int right = 0;
	int sum = 0;

	while (left != N) {
		if (sum == N) {
			cnt++;
			right++;
			sum += right;
		}
		else if (sum < N) {
			right++;
			sum += right;
		}
		else {
			left++;
			sum -= left;
		}
	}

	cout << cnt;

	return 0;
}
