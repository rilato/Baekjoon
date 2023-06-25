// 틀린 풀이

// 반례
// 3 100 3
// 출력 : -1, 내 답 : 1

#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, score, P, num;
	int min = 2000000000;
	int count = 1;

	cin >> N >> score >> P;

	for (int i = 0; i < N; i++) {
		cin >> num;

		if (num < min)
			min = num;

		if (num == score || num < score)
			break;

		++count;
	}

	if (count == N && score <= min)
		cout << -1;
	else
		cout << count;
}

// 틀린 풀이
// 반례가 너무 많고, 어디서 틀렸는지 조차 알기 힘들었다.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, score, P, num;
	int checkPoint = 0;
	vector<int> v;

	cin >> N >> score >> P;

	if (N == 0) {
		cout << 1;

		return 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> num;

		v.push_back(num);

		if (v[i] > score)
			checkPoint = i;
	}

	// 현재까지 기록된 점수의 마지막 값이 내 점수와 같고,
	// 랭킹 리스트가 이미 꽉 차있어서
	// 내 점수가 등록될 수 없는 경우
	if (N == P && v.back() == score)
		cout << -1;
	else
		cout << checkPoint + 2;
}

// 맞은 풀이
// 

#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, score, P;
	int cnt = 0;
	int my_rank = 1;
	int rank[100];

	cin >> N >> score >> P;

	for (int i = 0; i < N; i++) {
		cin >> rank[i];
	}

	for (int i = 0; i < N; i++) {
		if (score < rank[i])
			my_rank++;

		else if (score == rank[i])
			my_rank = my_rank;

		else
			break;

		cnt++;
	}

	if (cnt == P) my_rank = -1;

	if (N == 0) my_rank = 1;

	cout << my_rank;
}