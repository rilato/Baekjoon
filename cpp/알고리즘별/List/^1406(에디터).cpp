// �츮�� ��ǻ�Ϳ��� ���ڿ��� �Է����� �� ��Ÿ���� Ŀ����, �� Ŀ���� �������� �����ϴ� ����
// erase()�� insert() �Լ��� ���ڿ��� ������ �� �ð� ���⵵�� O(N)�̹Ƿ�, �Ź� �� ���ھ� �����ϰų� �߰��� ������ ���ڿ��� ���̿� ����Ͽ� �ð��� ������

// �� ������ �ذ��ϱ� ����, ������ ���� ������ ���� ȿ�������� ó���� �� �ִ� ����� ����ؾ� ��.
// C++�� STL�� <list>�� ����Ͽ� �� ������ �ذ��� �� ����.
// <list>�� ���� ���� ����Ʈ�� �����Ǿ� �־� ���԰� ������ O(1)�� ������.

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