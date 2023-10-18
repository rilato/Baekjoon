// 1. 책 이름을 key, 책 이름이 나온 빈도 수를 value로 한 map 변수를 만들어 정보를 저장한다.
// 2. map 자료구조는 자료를 저장할 떄 key값을 기준으로 오름차순으로 정렬되므로,
// 가장 빈도 수가 높은 값을 찾으면 바로 key값을 출력 후 프로그램을 종료하면 된다.

#include <iostream>
#include <map>

using namespace std;

int n, cnt;
map <string, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while (n--) {
        string bookName;

        cin >> bookName;

        m[bookName]++;
    }

    // map을 돌며 최대 값 찾기
    for (auto p : m)
        cnt = max(cnt, p.second);

    // key값을 기준으로 오름차순 정렬되므로, 값을 찾으면 바로 종료
    for (auto p : m) {
        if (p.second == cnt) {
            cout << p.first;
            return 0;
        }
    }

    return 0;
}
