// visited �迭 ���� ó���Ѵ�.
// �Լ��� ���ڷ� �� ���� ���� �־��ش�.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int ans[8];

void backtracking(int cnt, int start);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    backtracking(0, 0);

    return 0;
}

void backtracking(int cnt, int start) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << " ";
        }

        cout << '\n';

        return;
    }

    for (int i = start; i < N; i++) {
        ans[cnt] = arr[i];
        // ���� ������� ������ ū�� �ٽ� Ž��
        backtracking(cnt + 1, i);
    }
}