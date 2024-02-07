#include <iostream>

using namespace std;

int N, M;
int arr[101];
int ans[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        arr[i] = i;
        ans[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        int k = a;

        for (int j = c; j <= b; j++) {
            ans[k++] = arr[j];
        }

        for (int j = a; j < c; j++) {
            ans[k++] = arr[j];
        }

        for (int j = 1; j <= N; j++) {
            arr[j] = ans[j];
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}