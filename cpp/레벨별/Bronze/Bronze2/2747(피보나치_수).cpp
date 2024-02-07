#include <iostream>

using namespace std;

int N;
int arr[45] = { 0, };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;

    for (int i = 3; i <= N; i++)
        arr[i] = arr[i - 2] + arr[i - 1];

    cout << arr[N];
}