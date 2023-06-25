// LIS의 원리를 알아야 한다.
// 벡터가 비어있거나, 벡터의 마지막 값보다 input값이 큰 경우, 벡터에 값을 넣는다.
// 그렇지 않은 경우 lower_bound로 input이 들어갈 위치를 확인하고, 그 자리의 값을 input으로 교체한다.

// https://ferrante.tistory.com/54
// https://canoe726.tistory.com/9

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a;
vector<int> v;

int main() {
	cin >> a;
	for (int i = 0; i < a; i++) {
		int input;

		cin >> input;

		if (v.empty() || v.back() < input) {
			v.push_back(input);
		}

		// lower_bound는 이분 탐색을 활용하므로 정렬된 배열이 필요하다.
		// 하지만 v가 증가하는 수열이므로, 정렬할 필요가 없다.

		else {
			// lower_bound의 위치에 해당하는 값 (*를 통해 주소가 아닌, 값을 나타냄)을 input으로 대체한다.
			*lower_bound(v.begin(), v.end(), input) = input;
		}
	}

	cout << v.size();
}