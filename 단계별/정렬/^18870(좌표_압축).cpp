//lower_bound, upper_bound는 <algorithm> 헤더에 들어 있다.
//
//두 함수가 정상적으로 작동하기 위해서는 먼저 범위 내의 원소들이 비내림차순(≈오름차순)으로 정렬되어 있어야 한다.이진탐색으로 구현되기 때문이다.
//
//각 함수 설명은 다음과 같다.
//
//lower_bound(first, last, key)는 범위에서 key 이상인 첫 번째 원소의 위치를 반환한다.
//upper_bound(first, last, key)는 범위에서 key를 초과하는 첫 번째 원소의 위치를 반환한다.
//
//4번째 인자로 Comparator가 들어갈 수 있다.
//
//<예시>
//vector<int> v = { -2, -2, -1, -1, 0, 0, 0, 1, 1 };
//cout << lower_bound(v.begin(), v.end(), 0) - v.begin() << '\n';  // 4
//cout << upper_bound(v.begin(), v.end(), 0) - v.begin() << '\n';  // 7
//
//lower_bound(0)에서 0 이상인 값이 처음으로 나오는 인덱스 4가 반환되고, upper_bound(0)에서는 0을 초과하는 값이 처음 나오는 인덱스 7이 반환된다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num;
	vector<int> beforeV, afterV;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> num;
		beforeV.push_back(num);
		afterV.push_back(num);
	}

	sort(afterV.begin(), afterV.end());
	afterV.erase(unique(afterV.begin(), afterV.end()), afterV.end());

	for (int i = 0; i < beforeV.size(); i++) {
		cout << lower_bound(afterV.begin(), afterV.end(), beforeV[i]) - afterV.begin() << ' ';
	}
}

// 시간 초과가 난 풀이.
// 출력 시 for문을 두 번 돌면서 시간 초과가 발생한 듯하다.
// find함수를 써도, 시간복잡도가 O(N)이기 때문에 시간 초과가 발생한다.

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int input, num;
//	vector<int> beforeV, afterV;
//
//	cin >> input;
//
//	for (int i = 0; i < input; i++) {
//		cin >> num;
//		beforeV.push_back(num);
//		afterV.push_back(num);
//	}
//
//	// 정렬 후 인덱스 i가 곧 자신보다 작은 수의 개수
//	sort(afterV.begin(), afterV.end());
//	afterV.erase(unique(afterV.begin(), afterV.end()), afterV.end());
//
//	for (int i = 0; i < beforeV.size(); i++) {
//		for (int j = 0; j < afterV.size(); j++) {
//			if (beforeV[i] == afterV[j])
//				cout << j << ' ';
//		}
//	}
//}