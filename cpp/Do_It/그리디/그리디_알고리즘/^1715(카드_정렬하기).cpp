// 항상 최소 값 두 개를 뽑기 위해, priority queue를 사용한다.

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, num;
	int answer = 0;

	cin >> N;

	// 우선순위 큐는 기본적으로 가장 큰 값이 가장 큰 우선순위를 가지므로(내림차순)
	// 오름차순으로 정렬하려면 greater<int>를 써주어야 한다.
	priority_queue <int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}

	// priority_queue를 이용하면, 수가 자동 정렬되므로
	// 가장 작은 카드 묶음 2개를 쉽게 뽑을 수 있다.
	while (pq.size() != 1) {
		int num1 = pq.top();
		pq.pop();

		int num2 = pq.top();
		pq.pop();

		answer += (num1 + num2);

		pq.push(num1 + num2);
	}

	cout << answer;

	return 0;
}