// insertion sort�� ������ ���.
// �ð��ʰ��� �߻��ϹǷ� �ٸ� ����� �����ؾ� �Ѵ�.

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
//				// x���� ������, ���� y���� ���� y������ ū ��Ȳ => ������ x���� �����Ƿ�, y���� �ٲ��ش�.
//				if (arr[j][1] > arr[j + 1][1]) {
//					temp = arr[j + 1][1];
//					arr[j + 1][1] = arr[j][1];
//					arr[j][1] = temp;
//				}
//				else
//					continue;
//			}
//
//			// x���� y�� ��� �ٲ��ش�.
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



// �ð� �ʰ��� �����ϱ� ���ؼ���, vector �� pair��, sort �Լ��� �̿��ؾ� �Ѵ�.

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

	// vector�� ���� �ֱ� ���ؼ���, �ε������� ���� �ִ� ���� �ƴ� ������ push_back�� ����Ѵ�.
	// ���� pair�� ���� �ֱ� ���ؼ�, ()�ȿ� {}�� �� ���� �����ش�.
	for (int i = 0; i < input; i++) {
		cin >> x >> y;
		coordinate.push_back({ x, y });
	}

	// sort(coordinate, coordinate + input)�� �ν����� ���Ѵ�.
	// vector�� begin(), end()�� ����ؾ� �Ѵ�.
	sort(coordinate.begin(), coordinate.end());

	// coordinate[i][0], coordinate[i][1]�� �ν����� ���Ѵ�.
	// pair�� coordinate[i].first, coordinate[i].second�� ����ؾ� �Ѵ�.
	for (int i = 0; i < input; i++)
		cout << coordinate[i].first << ' ' << coordinate[i].second << '\n';
}