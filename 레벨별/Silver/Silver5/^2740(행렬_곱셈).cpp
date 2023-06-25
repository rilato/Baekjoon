#include <iostream>

using namespace std;

int arr1[100][100];
int arr2[100][100];
int ans[100][100];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr1[i][j];
        }
    }

    cin >> M >> K;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                ans[i][j] += arr1[i][k] * arr2[k][j];
            }
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}