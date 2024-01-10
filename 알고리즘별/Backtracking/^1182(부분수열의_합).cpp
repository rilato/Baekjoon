// 6 0
// 0 -7 -3 -2 5 8
// 더해서 0을 만든다고 치자. 0 / -3 -2 5 / 0 -2 -3 5 총 3가지 경우의 수가 있다. 즉, 조합의 개수를 구하면 된다.

// 주의점 1) 연속된 수의 합을 찾는 것이 아니다.
// ex) N = 4, sum = 0, arr = [100, 100, 100, -100]일 때, 연속된 수의 합이라면 답이 1개이다.하지만(100, -100)조합이 3번 가능하므로 답이 3개이다.

// 주의점 2) 부분집합의 합이 아니니 중복이 포함된다.
// ex) N = 4, sum = 1, arr = [1, -1, 1, 2]일 때, 부분집합의 합이라면[1], [-1, 2], [1, -1, 1]로 답이 2개이다.하지만 첫번째 1과 세번째 1은 다른 1로 처리해야한다.그래서[1], [1], [-1, 2], [1, -1, 1]로 답이 4개이다.

#include <iostream>
#include <vector>

using namespace std;

int N, S;
int cnt = 0;
vector <int> v;

void Backtracking(int index, int sum);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    Backtracking(0, 0);

    cout << cnt;

    return 0;
}

void Backtracking(int index, int sum) {
    // 모든 수를 다 더하면 리턴
    if (index == N) {
        return;
    }

    // 지금까지의 합 + 현재 보는 값 == S이면, 카운트 + 1
    // sum == S가 아닌, sum + v[index] == S를 하는 이유는,
    // 맨 마지막 인덱스에 도달했을 때, 위의 if문에서 return을 먼저 만나므로, 맨 마지막 인덱스에 대한 합을 계산하기 위함.
    if (sum + v[index] == S) {
        cnt++;
        //return;	//return 하면 sum과 s 같아졌을때 그 이후 수열을 더하지 않고 return 해버린다
        // 예를 들어 타겟숫자가 0이고 순열이 -1 1 -2 2이 있다면
        // 부분순열 - 1 1 / -2 2 는 잡히지만 - 1 1을 잡고나면 리턴하므로 아무리 해도 - 1 1 - 2 2 부분수열이 잡히지 않는다.
    }

    // 나머지 경우라면 Backtracking 계속 실행
    Backtracking(index + 1, sum + v[index]);    // 현재 숫자를 더하고 다음 숫자를 받는 경우
    Backtracking(index + 1, sum);               // 현재 숫자를 안더하고 (넘어가고) 다음 숫자를 받는 경우
}