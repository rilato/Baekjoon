// https://softworking.tistory.com/230
// https://pirateturtle.tistory.com/237

#include <iostream>
#include <algorithm>

using namespace std;

// 입력될 순열
int num[10000] = { 0, };
int N;
// flag : 마지막 순열인지 확인을 위한 변수
int flag = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // 순열 입력
    for (int n = 0; n < N; n++) {
        cin >> num[n];
    }

    // 입력된 순열의 마지막부터 검사
    for (int i = N - 1; i > 0; i--) {
        // 왼쪽 원소(기준) < 오른쪽 원소
        if (num[i - 1] < num[i]) {
            // index : 교환할 원소의 인덱스 (i는 최소의 index를 찾기 위함)
            int index = i;
            // 기준 원소보다 오른쪽에 있으면서 
            for (int j = N - 1; j >= i; j--) {
                // 기준 원소보다 크면서 + 제일 작은 원소
                if (num[i - 1] < num[j] && num[j] < num[index]) {
                    index = j;
                }
            }

            // 교환 작업
            int temp = num[index];
            num[index] = num[i - 1];
            num[i - 1] = temp;

            // 기준 원소 우측 오름차순으로 정렬
            sort(num + i, num + N);

            // 마지막 순열이 아니라는 신호
            flag = 1;
            break;
        }
    }

    // 마지막 순열인 경우
    if (flag == 0) {
        cout << -1;
    }
    // 마지막 순열이 아닌 경우
    else {
        for (int n = 0; n < N; n++) {
            cout << num[n] << " ";
        }
    }

    return 0;
}