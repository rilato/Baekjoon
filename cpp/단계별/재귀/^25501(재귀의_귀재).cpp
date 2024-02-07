// 틀린 풀이
// 문제에서 제시한 재귀로 구현하면 시간 초과가 발생한다.

#include <iostream>

using namespace std;

int cntRecursion(string S, int start, int end, int count);
bool isPalindrome(string S, int start, int end);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    string S;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S;

        cout << isPalindrome(S, 0, S.size() - 1) << " " << cntRecursion(S, 0, S.size() - 1, 0) << '\n';
    }
}

int cntRecursion(string S, int start, int end, int count) {
    count++;

    if (start >= end || S[start] != S[end])
        return count;

    else {
        start++;
        end--;
        return cntRecursion(S, start, end, count);
    }
}

bool isPalindrome(string S, int start, int end) {
    if (start >= end)
        return true;

    if (S[start] != S[end])
        return false;

    else {
        start++;
        end--;
        return isPalindrome(S, start, end);
    }
}


// 맞은 풀이
// for문으로 구현한다.

#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    string S;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int k;
        bool flag = false;
        int cnt = 0;

        cin >> S;

        for (int j = 0; j <= S.size() / 2; j++) {
            k = S.size() - 1 - j;

            cnt++;

            if (j >= k)
                flag = true;

            if (S[j] != S[k])
                break;
        }

        cout << flag << " " << cnt << "\n";
    }
}