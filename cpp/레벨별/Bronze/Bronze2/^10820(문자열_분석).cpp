// T�� ������ �־����� �ʾ��� ��, ��� �Է��� �޾ƾ� ���� �� �ִ��� �ľ��Ѵ�.

#include <iostream>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string s;

    while (getline(cin, s)) {
        int arr[4] = { 0, };

        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                if (isupper(s[i]))
                    arr[1]++;
                else
                    arr[0]++;
            }
            else if (isdigit(s[i]))
                arr[2]++;
            else
                arr[3]++;
        }

        for (int i = 0; i < 4; i++) {
            cout << arr[i] << " ";
        }

        cout << '\n';
    }
}