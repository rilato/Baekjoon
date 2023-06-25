// 재귀를 이용한 백트래킹에 대해 익숙해질 필요가 있다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
bool visited[9] = { 0, };
vector <int> v;

void backtracking(int cnt);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    backtracking(0);

    return 0;
}

void backtracking(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }

        cout << '\n';

        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i])
            continue;

        visited[i] = true;
        v.push_back(arr[i]);
        backtracking(cnt + 1);
        v.pop_back();
        visited[i] = false;
    }
}