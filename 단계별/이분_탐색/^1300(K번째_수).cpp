// 틀린 풀이
// 1행부터 아래 행으로 내려갈수록 숫자가 점점 커진다는 잘못된 생각 때문에 문제가 발생했다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {

    // 이차원 배열의 행, 열 길이
    long long N, k;
    long long max;
    long long sum = 0;
    long long prevSum = 0;
    int row = 1;
    int column;

    cin >> N >> k;

    // 행렬을 대각선으로 갈른 후 반으로 접었을 때 행의 개수의 합이 곧 i다.
    max = 2 * N - 1;

    for (int i = max; i >= 1; i -= 2) {
        sum += i;

        if (k <= sum) {
            // 대각선을 제외한 오른쪽 수의 총 개수
            column = k - prevSum;
            // column은 대각선 라인으로부터 몇 개만큼 떨어져있는지를 나타낸다.
            column /= 2;
            // 진짜 column위치를 반환한다.
            column += row;

            break;
        }

        // 몇 번째 행인지는 row라는 변수로 따로 세어준다.
        row++;

        // 이전 단계의 합을 prevSum에 저장한다.
        prevSum = sum;
    }

    cout << row * column;
}


// 맞은 
// https://hyeo-noo.tistory.com/64 참고

//N = 5, K = 17 이 주어졌을 때.

//이 문제를 이분탐색으로 풀기 위해서 5x5의 절반인 12를 최초 mid로 설정하자(lo = 0, hi = 25)

//12는 위 표에서 몇 번째일까 ?

//1행은 모두 12보다 같거나 작다->cnt += 5
//2행도 모두 12보다 같거나 작다->cnt += 5
//3행은 4열까지만 12보다 같거나 작다->cnt += 4
//4행은 3열까지만 12보다 같거나 작다->cnt += 3
//5행은 2열까지만 12보다 같거나 작다->cnt += 2
//cnt = 19가 되고 K = 17보다 크기 때문에 mid값을 감소시켜야 함을 알 수 있다->hi = mid - 1, mid = (lo + hi) / 2 = 5

//mid는(lo + hi) / 2 로 재설정해주고 위 작업을 반복하면 O(NlogK)만에 K번째 수를 구할 수 있다.

#include <iostream>

using namespace std;

void Matrix_BS(long long N, long long K);
long long check_count(long long N, long long mid, long long K);

int main() {

    // 이차원 배열의 행, 열 길이
    long long N, K;

    cin >> N >> K;

    // 총 NlogN만큼의 시간 복잡도를 갖는다.
    Matrix_BS(N, K);
}

void Matrix_BS(long long N, long long K) {
    long long left = 1;
    long long right = N * N;

    long long answer = 0;

    // 이진탐색이므로 logN의 시간 복잡도를 갖는다.
    while (left <= right) {
        long long mid = (left + right) / 2;

        // mid보다 작거나 같은 수의 개수가 K보다 작으면, K번째 수는 적어도 현재 mid보다 크다는 것이다.
        // 따라서 left를 mid보다 하나 크게 설정한다.
        if (check_count(N, mid, K) < K)
            left = mid + 1;
        else {
            answer = mid;
            right = mid - 1;
        }
    }

    cout << answer;
}

// for문을 돌기 때문에 N만큼의 시간 복잡도를 갖는다.
// mid보다 작거나 같은 수의 개수를 센다.
long long check_count(long long N, long long mid, long long K) {
    long long count = 0;

    for (int i = 1; i <= N; i++)
        // (한 행 전체 길이인 N)과, (중간 값 / 해당 행 = 중간 값이 어느 위치에 있는지 반환)을 비교하여, 작은 값을 더한다.
        count += min(N, mid / i);

    return count;
}