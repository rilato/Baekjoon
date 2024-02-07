// 우리가 컴퓨터에서 문자열을 입력했을 때 나타나는 커서와, 그 커서의 움직임을 구현하는 문제
// erase()와 insert() 함수는 문자열을 조작할 때 시간 복잡도가 O(N)이므로, 매번 한 글자씩 삭제하거나 추가할 때마다 문자열의 길이에 비례하여 시간이 증가함

// 이 문제를 해결하기 위해, 삭제와 삽입 연산을 보다 효율적으로 처리할 수 있는 방법을 사용해야 함.
// C++의 STL인 <list>를 사용하여 이 문제를 해결할 수 있음.
// <list>는 이중 연결 리스트로 구현되어 있어 삽입과 삭제가 O(1)에 가능함.

#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S, input;
    int M;

    cin >> S >> M;

    list <char> charList(S.begin(), S.end());
    auto cursor = charList.end();

    for (int i = 0; i < M; i++) {
        cin >> input;

        if (input == "L") {
            if (cursor != charList.begin()) {
                cursor--;
            }
        }
        else if (input == "D") {
            if (cursor != charList.end()) {
                cursor++;
            }
        }
        else if (input == "B") {
            if (cursor != charList.begin()) {
                cursor = charList.erase(--cursor);
            }
        }
        else {
            char c;

            cin >> c;

            charList.insert(cursor, c);
        }
    }

    for (char c : charList) {
        cout << c;
    }

    return 0;
}