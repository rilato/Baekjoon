#include <iostream>
#include <stack>

using namespace std;

stack <int> S;
int N, T;
int cnt = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N; // 학생들의 수. 

	while (N--) {
		cin >> T;

		if (T == cnt)
			cnt++; // 현재 순번과 일치한다면 들여보낸다. 
		else
			S.push(T); // 아니면 스택에서 기다리도록 한다. 

		// 스택 맨 위가 현재 순번과 일치한다면 들여보낸다.
		while (!S.empty()) {
			if (S.top() == cnt) {
				S.pop();
				cnt++;
			}
			else {
				break;
			}
		}
	}

	if (S.empty())
		cout << "Nice"; // 스택이 비었다면, 잘 해결된 것.
	else
		cout << "Sad";

    return 0;
}
