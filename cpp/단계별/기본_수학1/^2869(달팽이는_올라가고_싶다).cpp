// for문으로 구현할 수 있지만, 시간이 오래걸리므로, 수학적으로 모델링한 후 구현한다.

#include <iostream>

using namespace std;

int main() {
	int day, night, oneDay, days, height;

	cin >> day >> night >> height;

	height -= day;	// height - day만큼만 도달하면 다음날 아침에 day만큼 오르면 미끄러지지 않는다.
	days = height / (day - night) + 1;	// height - day만큼 가는데 걸리는 날짜를 구한다. 위에서 day만큼 빼줬으므로, 하루를 더하고 시작한다.

	if (height % (day - night) == 0)	// 이 때, 나머지가 0인 경우는 days만큼 오르고 마지막 날에 day만큼 오르면 되지만,
		cout << days;
	else								// 나머지가 0이 아닌 경우는 정상에 도달하기에 이동거리가 조금 모자라므로, 1을 추가로 더해줘야 한다.
		cout << days + 1;
}