// 15650�� ���� (N�� M (2))�� �����ϴ�.
// ������ ���� ��, ���� ������ �߰��Ͽ� ���� ����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector <char> alphabet;
vector <bool> visited;
vector <char> answer;

void Recursive(int depth, int index);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;

    alphabet.resize(C);
    visited.resize(C);
    answer.resize(L);

    for (int i = 0; i < C; i++) {
        cin >> alphabet[i];
    }

    sort(alphabet.begin(), alphabet.end());

    Recursive(0, 0);

    return 0;
}

void Recursive(int depth, int index) {
    if (depth == L) {
        int consonant = 0;  // ���� �� ī��Ʈ
        int vowel = 0;      // ���� �� ī��Ʈ

        for (int i = 0; i < L; i++) {
            // ���� ���� ����
            if (answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'i' || answer[i] == 'o' || answer[i] == 'u') {
                vowel++;
            }
            // ���� ���� ����
            else {
                consonant++;
            }
        }

        if (consonant >= 2 && vowel >= 1) {
            for (int i = 0; i < L; i++) {
                cout << answer[i];
            }

            cout << '\n';
        }

        return;
    }

    for (int i = index; i < C; i++) {
        if (!visited[i]) {
            answer[depth] = alphabet[i];
            visited[i] = true;
            Recursive(depth + 1, i + 1);
            visited[i] = false;
        }
    }
}