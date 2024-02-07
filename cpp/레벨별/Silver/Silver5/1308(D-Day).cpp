// 정말 맞은것 같은데 틀렸다고 나온 풀이

#include <iostream>

using namespace std;

// 윤년을 확인하는 함수
bool check(int year);

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int year, month, day;
	int Dyear, Dmonth, Dday;
	// 윤년의 개수를 세는 변수
	int count = 0;
	// 두 연도의 차이에 1을 더 빼줄 변수와 최종 날짜의 합을 적을 변수
	int years, gap;
	// 인덱스가 월, 값은 각 월에 해당하는 일 수
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cin >> year >> month >> day;
	cin >> Dyear >> Dmonth >> Dday;

	if (Dyear >= year + 1000 && Dmonth >= month && Dday >= day)
		cout << "gg";
	else {
		// 입력 년도의 나머지 날짜 계산, 해당 월에서 남은 날짜로 값을 초기화
		int after_day = days[month] - day;
		// D day년도의 앞 날짜 계산, 해당 월에서 이전 날짜로 값을 초기화
		int before_day = Dday;

		// 시작 년도에서 남은 날짜 계산
		for (int i = month + 1; i < 13; i++)
			after_day += days[i];

		// D-Day 년도에서 앞선 날짜 계산
		for (int i = 1; i < Dmonth; i++)
			before_day += days[i];

		// 두 년도의 차이에서 1을 더 빼준다.
		// 그 값이 곧 1년 365일이 모두 더해질 년의 개수다.
		// 또한 입력년도와 D day 년도를 제외한 윤년의 횟수를 센다.
		// 윤년이 있을 때마다 1을 더한다.
		// 위에서는 1년을 365일로 했지만, 윤년은 1년에 하루가 더 많으므로
		// 윤년의 등장 횟수가 곧 1일을 더할 횟수와 동일하다.

		// 입력 년도의 윤년 날짜 처리
		if (check(year)) {
			if (month <= 2)
				after_day += 1;
		}

		// D day년도의 윤년 날짜 처리
		if (check(Dyear)) {
			if (month >= 3)
				before_day += 1;
		}

		// 두 년도 사이에서 윤년의 개수 파악
		for (int i = year + 1; i < Dyear; i++) {
			if (check(i))
				++count;
		}

		years = Dyear - year - 1;
		// 총 일수 계산
		gap = years * 365 + count + after_day + before_day;

		cout << "D-" << gap;
	}
}

// 윤년을 확인하는 함수
bool check(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	return false;
}