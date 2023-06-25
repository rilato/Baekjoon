// ctime을 이용한 현재 날짜 출력 방법을 익혀둔다.

#include <iostream>
#include <ctime>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    struct tm* t;

    time_t timer;
    timer = time(NULL);
    t = localtime(&timer);

    cout << t->tm_year + 1900 << "-";
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mon + 1 << "-";
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mday;
}