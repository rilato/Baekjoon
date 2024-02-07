// 틀린 풀이
// 그때 그때 인덱스 사이의 알파벳 개수를 센다.
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


// 맞은 풀이
// 지금까지의 합을 저장해놓고, 그것을 이용하는 누적 합을 이용한다.

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
        // 이전에 저장된 값들을 바탕으로, 다음의 값들을 미리 세팅해놓기
        if (i) {
            for (int j = 0; j < 26; j++) {
                arr[i][j] = arr[i - 1][j];
            }
        }
        // 다음의 값에 대해 해당 알파벳에 1더해주기
        alphabetToAscii = S[i] - 'a';
        arr[i][alphabetToAscii]++;
    }

    cin >> input;

    for (int i = 0; i < input; i++) {
        char alphabet;
        int startIndex, endIndex, start, end;

        cin >> alphabet >> startIndex >> endIndex;

        alphabetToAscii = alphabet - 'a';

        // startIndex 가 아닌, startIndex - 1을 해줘야 원하는 값이 나온다!!
        // 1 ~ 6이라고 하면, 6에서 0을 빼줘야 1에서 6이 계산되기 때문이다!!
        // 언더플로우의 가능성을 배제하기 위해, 0인 경우는 0으로 계산하도록 한다.
        start = startIndex > 0 ? arr[startIndex - 1][alphabetToAscii] : 0;
        end = arr[endIndex][alphabetToAscii];

        cout << end - start << '\n';
    }
}