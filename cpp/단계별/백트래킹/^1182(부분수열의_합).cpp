// 조금 다른 방식의 백트래킹 방식을 알아본다.
// nqueen처럼 인자 두 개를 넣는다.

#include<iostream>

using namespace std;

int N, S;
int ans = 0;
int arr[21] = { 0, };

void backTracking(int index, int sum);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    backTracking(0, 0);

    cout << ans;
}

void backTracking(int index, int sum) {
    if (index == N)
        return;

    if (sum + arr[index] == S)
        ans++;

    backTracking(index + 1, sum + arr[index]);
    backTracking(index + 1, sum);
}