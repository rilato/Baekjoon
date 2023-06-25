// insertion sort를 변형한 방법.
// 시간초과가 발생하므로 다른 방법을 구상해야 한다.

//#include <iostream>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int input, temp;
//
//	cin >> input;
//
//	int** arr = new int*[input];
//
//	for (int i = 0; i < input; i++)
//		arr[i] = new int[2];
//
//	for (int i = 0; i < input; i++) {
//		cin >> arr[i][0] >> arr[i][1];
//	}
//
//	for (int i = 0; i < input - 1; i++) {
//		int j = i;
//
//		while (j >= 0 && arr[j][0] >= arr[j + 1][0]) {
//			if (arr[j][0] == arr[j + 1][0]) {
//				// x값은 같지만, 앞의 y값이 뒤의 y값보다 큰 상황 => 어차피 x값이 같으므로, y값만 바꿔준다.
//				if (arr[j][1] > arr[j + 1][1]) {
//					temp = arr[j + 1][1];
//					arr[j + 1][1] = arr[j][1];
//					arr[j][1] = temp;
//				}
//				else
//					continue;
//			}
//
//			// x값과 y값 모두 바꿔준다.
//			else {
//				temp = arr[j + 1][0];
//				arr[j + 1][0] = arr[j][0];
//				arr[j][0] = temp;
//
//				temp = arr[j + 1][1];
//				arr[j + 1][1] = arr[j][1];
//				arr[j][1] = temp;
//			}
//
//			--j;
//		}
//	}
//
//	for (int i = 0; i < input; i++)
//		cout << arr[i][0] << ' ' << arr[i][1] << '\n';
//
//	for (int i = 0; i < input; i++)
//		delete[] arr[i];
//
//	delete[] arr;
//}



// 시간 초과를 방지하기 위해서는, vector 중 pair와, sort 함수를 이용해야 한다.

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

	// vector에 값을 넣기 위해서는, 인덱싱으로 값을 넣는 것이 아닌 무조건 push_back을 사용한다.
	// 또한 pair에 값을 넣기 위해서, ()안에 {}로 두 값을 묶어준다.
	for (int i = 0; i < input; i++) {
		cin >> x >> y;
		coordinate.push_back({ x, y });
	}

	// sort(coordinate, coordinate + input)로 인식하지 못한다.
	// vector는 begin(), end()를 사용해야 한다.
	sort(coordinate.begin(), coordinate.end());

	// coordinate[i][0], coordinate[i][1]로 인식하지 못한다.
	// pair는 coordinate[i].first, coordinate[i].second를 사용해야 한다.
	for (int i = 0; i < input; i++)
		cout << coordinate[i].first << ' ' << coordinate[i].second << '\n';
}