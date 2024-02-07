// 배열의 type과 sum을 long long으로 선언해야 한다.
// 나머지 연산에서 필요한 공식을 익혀둔다 (교재 p.54)

#include <iostream>
#include <vector>

using namespace std;

int N, M;
long long cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	vector <long long> v(N, 0);
	vector <long long> c(M, 0);	// remainder를 저장하는 벡터의 사이즈는 M!

	cin >> v[0];

	for (int i = 1; i < N; i++) {
		cin >> v[i];

		v[i] += v[i - 1];
	}

	for (int i = 0; i < N; i++) {
		int remainder = v[i] % M;

		// 0 ~ i까지의 구간 합 자체가 0일 때 정답에 더하기
		if (remainder == 0)
			cnt++;

		// 나머지가 같은 애들의 개수 세어 해당 인덱스에 저장
		c[remainder]++;

		// 나머지가 같은 애 2개를 골라 둘을 빼주어야 구간합에서 나머지가 0이 됨!
		// ex) 1, 0, 0, 1, 0에서 첫 번째 1과 네 번째 1을 뽑아 둘을 빼면 1-1 = 0이 되고,
		// M으로 나누었을 때 나머지가 0이 됨!

		// 결국, 그러한 애들의 개수 중 2개를 뽑으면 됨
		// 따라서, nC2 = n * (n - 1) / 2;
	}

	// Index는 최대 M - 1까지임.
	// 따라서 M번 반복 수행.
	for (int i = 0; i < M; i++) {
		if (c[i] > 1) {
			cnt = cnt + (c[i] * (c[i] - 1) / 2);
		}
	}

	cout << cnt;

	return 0;
}