// Ʋ�� Ǯ��
// �׶� �׶� �ε��� ������ ���ĺ� ������ ����.
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    int input;

    cin >> S >> input;

    for (int i = 0; i < input; i++) {
        char alphabet;
        int startIndex, endIndex;
        int count = 0;

        cin >> alphabet >> startIndex >> endIndex;

        for (int j = startIndex; j <= endIndex; j++) {
            if (S[j] == alphabet)
                ++count;
        }

        cout << count << '\n';
    }
}


// ���� Ǯ��
// ���ݱ����� ���� �����س���, �װ��� �̿��ϴ� ���� ���� �̿��Ѵ�.

#include <iostream>

using namespace std;

string S;
int input, alphabetToAscii;
int arr[200002][26] = { 0, };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;

    for (int i = 0; i < S.size(); i++) {
        // ������ ����� ������ ��������, ������ ������ �̸� �����س���
        if (i) {
            for (int j = 0; j < 26; j++) {
                arr[i][j] = arr[i - 1][j];
            }
        }
        // ������ ���� ���� �ش� ���ĺ��� 1�����ֱ�
        alphabetToAscii = S[i] - 'a';
        arr[i][alphabetToAscii]++;
    }

    cin >> input;

    for (int i = 0; i < input; i++) {
        char alphabet;
        int startIndex, endIndex, start, end;

        cin >> alphabet >> startIndex >> endIndex;

        alphabetToAscii = alphabet - 'a';

        // startIndex �� �ƴ�, startIndex - 1�� ����� ���ϴ� ���� ���´�!!
        // 1 ~ 6�̶�� �ϸ�, 6���� 0�� ����� 1���� 6�� ���Ǳ� �����̴�!!
        // ����÷ο��� ���ɼ��� �����ϱ� ����, 0�� ���� 0���� ����ϵ��� �Ѵ�.
        start = startIndex > 0 ? arr[startIndex - 1][alphabetToAscii] : 0;
        end = arr[endIndex][alphabetToAscii];

        cout << end - start << '\n';
    }
}