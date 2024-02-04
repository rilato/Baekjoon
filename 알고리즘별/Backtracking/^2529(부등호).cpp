#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
string S;
vector<char> input;         // 부등호를 저장하는 배열
vector<bool> visited(10);   // 숫자의 방문 여부를 저장하는 배열
vector<string> v;           // 현재까지의 숫자를 저장하는 배열
vector<long long> answer;    // 가능한 숫자 조합을 저장하는 배열

// 백트래킹 함수
void Backtracking(int depth);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    input.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    // 맨 처음 수 넣고 시작
    for (int i = 0; i < 10; i++) {
        visited[i] = true;
        v.push_back(to_string(i));
        Backtracking(0);
        v.pop_back();
        visited[i] = false;
    }

    sort(answer.begin(), answer.end());

    string min = to_string(answer[0]);
    string max = to_string(answer[answer.size() - 1]);

    // 가장 작은 수 또는 가장 큰 수의 사이즈가 N이라면, 맨 앞에 0 붙이기
    if (min.size() == N) {
        string temp = "0";
        temp += min;
        min = temp;
    }

    if (max.size() == N) {
        string temp = "0";
        temp += max;
        max = temp;
    }

    // 결과 출력
    cout << max << '\n' << min;

    return 0;
}

// 백트래킹 함수 정의, depth는 input의 index로, 입력된 부등호를 살피기 위해 존재
void Backtracking(int depth) {
    if (depth == N) {
        // 현재까지의 숫자를 문자열로 합쳐서 숫자 배열에 추가
        string temp = "";

        for (int i = 0; i < v.size(); i++) {
            temp += v[i];
        }

        answer.push_back(stoll(temp));

        return;
    }

    // 0부터 9까지 들어갈 숫자 찾기
    for (int i = 0; i < 10; i++) {
        if (!visited[i]) {
            // 부등호를 검사하여 조건이 맞으면 숫자를 선택
            if ((input[depth] == '<' && stoi(v.back()) < i) || (input[depth] == '>' && stoi(v.back()) > i)) {
                visited[i] = true;
                v.push_back(to_string(i));
                Backtracking(depth + 1);
                v.pop_back();
                visited[i] = false;
            }
        }
    }
}
