#include <iostream>

using namespace std;

int main() {
	int hour, min, time;
	int carry = 0;
	int remain;

	cin >> hour >> min >> time;

	carry = time / 60;
	remain = time % 60;

	// ���� �ð��� 60���� �Ѵ� ���
	if (min + remain >= 60) {
		min += remain - 60;
		++carry;
	}
	// ���� �ð��� 60���� �ȵǴ� ���
	else
		min += remain;

	// ���� �Ϸ� �ð��� 24�ø� �Ѵ� ���
	if (hour + carry >= 24)
		hour += carry - 24;
	// ���� �Ϸ� �ð��� 24�ø� ���� �ʴ� ���
	else
		hour += carry;

	cout << hour << ' ' << min;
}