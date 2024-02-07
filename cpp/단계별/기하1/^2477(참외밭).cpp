// 빼야할 작은 정사각형을 어떻게 구해야 하는지가 관건이다.

// 틀린 풀이

#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, direction, length, size;
    int arr[6] = { 0, };
    int max_width = 0;
    int max_width_index = 0;
    int max_height = 0;
    int max_height_index = 0;
    int my_index = 0;
    int small_len1 = 0;
    int small_len2 = 0;

    cin >> K;

    for (int i = 0; i < 6; i++) {
        cin >> direction >> length;

        arr[i] = length;

        if (direction == 1 || direction == 2) {
            if (length > max_width) {
                max_width = length;
                max_width_index = i;
            }
        }
        else {
            if (length > max_height) {
                max_height = length;
                max_height_index = i;
            }
        }
    }

    my_index = max_width_index > max_height_index ? max_width_index : max_height_index;
    // 빼야할 부분의 너비는 두 번째로 나온 긴 너비에서 2만큼 더 간 곳에 위치
    small_len1 = arr[(my_index + 2) % 6];
    // 빼야할 부분의 높이는 가장 긴 높이에서 4만큼 더 간 곳에 위치
    small_len2 = arr[(my_index + 3) % 6];

    cout << K * (max_width * max_height - small_len1 * small_len2);
}


// 맞은 풀이

#include <iostream>

using namespace std;

int N;
int arr[6 + 2][2 + 2];  // 주어지는 방향, 길이쌍
int cnt[4]; // 방향 별 등장 횟수 저장

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s = 1; // 작은 사각형의 넓이
    int b = 1; // 큰 사각형의 넓이

    // 입력 받기
    cin >> N;

    for (int i = 0; i < 6; i++) {
        cin >> arr[i][0] >> arr[i][1];
        cnt[arr[i][0]]++;
    }

    for (int i = 0; i < 6; i++) {

        if (cnt[arr[i][0]] == 1)
            // 한 번씩 등장하는 방향이다
            b *= arr[i][1]; // 큰 사각형의 너비/높이이다

        int n = (i + 1) % 6;
        int nn = (i + 2) % 6;
        // 나(I)랑 다다음거(nn)랑 같으면 그 사이에 있는 것(n)이 작은 사각형의 너비/높이이다.
        if (arr[i][0] == arr[nn][0]) s *= arr[n][1];
    }

    cout << (b - s) * N;
}