#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int month, day, gap;
    // 전 월까지 일 수들의 합을 표시
    int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
    string yoil[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

    cin >> month >> day;

    gap = days[month] + day - 1;

    cout << yoil[gap % 7];
}