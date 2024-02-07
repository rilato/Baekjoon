// 15650번 문제 (N과 M (2))와 유사하다.
// 조합을 구한 후, 적정 조건을 추가하여 답을 출력한다.

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
        int consonant = 0;  // 자음 수 카운트
        int vowel = 0;      // 모음 수 카운트

        for (int i = 0; i < L; i++) {
            // 모음 개수 세기
            if (answer[i] == 'a' || answer[i] == 'e' || answer[i] == 'i' || answer[i] == 'o' || answer[i] == 'u') {
                vowel++;
            }
            // 자음 개수 세기
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