// 틀린 풀이
// 반례
// dread bread
// 답 : 2 / 출력 : 1

#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string A, B;
    int arrA[26] = { 0, };
    int arrB[26] = { 0, };
    int count = 0;

    cin >> A >> B;

    for (int i = 0; i < A.size(); i++)
        arrA[A[i] - 'a']++;

    for (int i = 0; i < B.size(); i++)
        arrB[B[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        if (arrA[i] && arrB[i])
            count += arrA[i] + arrB[i];

    cout << A.size() + B.size() - count;
}

// 맞은 풀이

#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string A, B;
    int arrA[26] = { 0, };
    int arrB[26] = { 0, };
    int count = 0;

    cin >> A >> B;

    for (int i = 0; i < A.size(); i++)
        arrA[A[i] - 'a']++;

    for (int i = 0; i < B.size(); i++)
        arrB[B[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        if (arrA[i] != arrB[i])
            count += abs(arrA[i] - arrB[i]);

    cout << count;
}