#include <iostream>

using namespace std;

int main() {
	int hour, min, time;
	int carry = 0;
	int remain;

	cin >> hour >> min >> time;

	carry = time / 60;
	remain = time % 60;

	// 조리 시간이 60분이 넘는 경우
	if (min + remain >= 60) {
		min += remain - 60;
		++carry;
	}
	// 조리 시간이 60분이 안되는 경우
	else
		min += remain;

	// 조리 완료 시간이 24시를 넘는 경우
	if (hour + carry >= 24)
		hour += carry - 24;
	// 조리 완료 시간이 24시를 넘지 않는 경우
	else
		hour += carry;

	cout << hour << ' ' << min;
}