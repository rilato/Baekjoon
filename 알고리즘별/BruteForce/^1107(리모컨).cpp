// 틀린 풀이
// 백트래킹으로 접근하였다.
// 반례가 존재한다.
// 10 
// 9
// 1 2 3 4 5 6 7 8 9
// 답 : 11 / 내 답 : 12

#include <iostream>
#include <vector>

using namespace std;

int N, M, num, tempN;
int jarisu = 0;
bool notIn[10] = { false, };
vector <int> v;
vector <int> combination;
int cnt = 2100000000;

void Backtracking(int depth, int index);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    tempN = N;

    while (tempN) {
        tempN /= 10;
        jarisu++;
    }

    for (int i = 0; i < M; i++) {
        cin >> num;

        notIn[num] = true;
    }

    for (int i = 0; i < 10; i++) {
        if (!notIn[i]) {
            v.push_back(i);
        }
    }

    // combination 배열에 N의 자리수 만큼의 공간을 확보한다.
    combination.resize(jarisu);

    // 100인 경우, cnt는 0이므로 Backtracking을 거치지 않음.
    if (N != 100) {
        Backtracking(0, 0);
    }
    else {
        cnt = 0;
    }

    cout << cnt;

    return 0;
}

// 가능한 숫자 조합을 구하여 gap을 구한 후, 최소한의 gap을 찾는다.
void Backtracking(int depth, int index) {
    if (depth == jarisu) {
        int number = 0;

        // 숫자 조합으로 가능한 숫자 만들기
        for (int i = 0; i < combination.size(); i++) {
            number += combination[i];
            number *= 10;
        }

        number /= 10;

        // 자리수만큼 숫자를 누르고, +, -를 몇 번 눌러야 하는지 카운트
        cnt = min(cnt, jarisu + abs(N - number));

        //for (int i = 0; i < combination.size(); i++) {
        //    cout << combination[i];
        //}

        //cout << '\n';

        return;
    }

    // 같은 숫자 중복을 포함하여 숫자를 나열하는 방법을 모두 구하기 위해 Backtracking함수를 두 번 사용
    for (int i = index; i < v.size(); i++) {
        combination[depth] = v[i];
        Backtracking(depth + 1, index + 1);
        Backtracking(depth + 1, index);
    }
}


// 옳은 풀이
// 문제에서 주어진 최대 범위는 5000000이지만, 그 위에서 내려가는 경우를 생각해야 하기 때문에 실제적으로 범위는 1000000까지 잡아줘야 한다.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, num, minimum;
bool notIn[10] = { false, };    // false는 제대로 동작하는 버튼, true는 동작하지 않는 버튼
vector <int> v;

bool check(int now);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> num;

        notIn[num] = true;
    }

    string st = to_string(N);

    // 우선, 현재 100번 채널에서 N 번 채널까지 이동하기 위해 버튼을 눌러야 하는 최대 횟수는 + 혹은 - 버튼만을 눌러야 하는 경우다.
    // 따라서 100-N의 절댓값이 최댓값이 된다.
    minimum = abs(N - 100);

    // 500000의 두 배인 1000000까지 살펴야 한다.
    for (int i = 0; i <= 1000000; i++) {
        // 현재 보고 있는 숫자가 고장난 버튼을 포함하고 있지 않은지 확인한다.
        if (check(i)) {
            // 모두 고장나지 않은 버튼이라면, abs(N - num) (+또는 - 버튼 누른 횟수) + 현재 보고 있는 숫자의 길이(숫자 버튼 누른 횟수)
            int tmp = abs(N - i) + to_string(i).size();
            minimum = min(minimum, tmp);
        }
    }

    cout << minimum << endl;

    return 0;
}

bool check(int now) {
    string s = to_string(now);

    // 현재 보고있는 숫자의 각 자리수를 확인한다.
    for (int i = 0; i < s.size(); i++) {
        // 동작하지 않는 버튼을 포함하는 숫자라면, false를 리턴한다.
        if (notIn[s[i] - 48]) {
            return false;
        }
    }

    // 모두 동작하는 버튼이라면 true를 리턴한다.
    return true;
}