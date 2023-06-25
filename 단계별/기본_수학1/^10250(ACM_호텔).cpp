// 1층인 경우와 꼭대기 층인 경우 예외가 발생할 수 있으므로 고려해야 한다.

#include <iostream>

using namespace std;

int main() {
	int input, width, height, order, floor, roomNumber;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> height >> width >> order;

		if (order % height != 0) {
			roomNumber = order / height + 1; // 몇 번째 방인지
			floor = order % height;		// 몇 층인지
		}

		else {			        // 층 수 == N번째 손님
			roomNumber = order / height;
			floor = height;
		}

		cout << floor * 100 + roomNumber << '\n';
	}
}