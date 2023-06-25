// ipad 필기 참고
// https://codnote.tistory.com/3


#include <iostream>

using namespace std;

int arr[500000];
int sorted[500000];
int cnt = 0;
int result = -1;
void merge_sort(int low, int high, int K);
void merge(int low, int mid, int high, int K);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sorted[i] = arr[i];
    }

    merge_sort(0, N - 1, K);

    cout << result;
}

void merge_sort(int low, int high, int K) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;

        merge_sort(low, mid, K);
        merge_sort(mid + 1, high, K);
        merge(low, mid, high, K);
    }
}

void merge(int low, int mid, int high, int K) {
    int i, j, k;

    i = low; j = mid + 1; k = 1;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            sorted[k++] = arr[i++];
        }
        else {
            sorted[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        sorted[k++] = arr[i++];
    }

    while (j <= high) {
        sorted[k++] = arr[j++];
    }

    i = low;
    k = 1;

    while (i <= high) {
        arr[i++] = sorted[k++];

        if (++cnt == K) {
            // 위에서 i++ 해줬으므로, 결과에는 i에서 1을 다시 뺀 인덱스 값을 넣어줘야 함!
            result = arr[i - 1];
            break;
        }
    }
}