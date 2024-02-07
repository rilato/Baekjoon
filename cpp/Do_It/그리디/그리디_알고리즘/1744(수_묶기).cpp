#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, num;
int answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	deque <int> dq;

	for (int i = 0; i < N; i++) {
		cin >> num;

		dq.push_back(num);
	}

	sort(dq.begin(), dq.end());

	while (!dq.empty()) {
    // 앞 쪽부터 봐야 그리디하게 작은 수 끼리 곱했을 때 큰 수가 나오도록 할 수 있음 
		int num1 = dq.front();

		if (num1 < 0) {
			dq.pop_front();

			if (dq.empty()) {
				answer += num1;
				break;
			}

			int num2 = dq.front();

      // 음수와 음수의 곱 또는 음수와 0의 곱은 항상 양수 또는 0 이상이므로 곱해서 더해줌
			if (num2 <= 0) {
				answer += num1 * num2;
			}

      // 음수와 양수가 있는 경우, 두 수는 더하는게 베스트지만, 일단 음수만 더하고 빠져나감
			else {
				answer += num1;
				break;
			}

			dq.pop_front();
		}

    // 0은 일단 다 빼기
		else if (num1 == 0) {
			dq.pop_front();
		}

		else {
			break;
		}
	}

  // 양수를 대상으로 돌리기
	while (!dq.empty()) {
    // 뒷 쪽부터 봐야 그리디하게 큰 수를 뽑아 곱할 수 있음
		int num1 = dq.back();

		dq.pop_back();

		if (dq.empty()) {
			answer += num1;
			break;
		}

		int num2 = dq.back();

		dq.pop_back();

		if (num1 > 1 && num2 > 1) {
			answer += num1 * num2;
		}

		else {
			answer += num1 + num2;
		}
	}

	cout << answer;

	return 0;
}
