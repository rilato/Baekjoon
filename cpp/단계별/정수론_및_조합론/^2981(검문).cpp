// https://cocoon1787.tistory.com/214 참고

// 시간 초과가 난 풀이
// 정답은 바르게 출력되는 듯하다.
// 하지만 과도한 for문 중첩이 시간 초과로 이어다.

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int arr[100];
	int remain[100];
	int max = 0;
	int count = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		if (arr[i] > max)
			max = arr[i];
	}

	for (int i = 2; i < max; i++) {
		for (int j = 0; j < N; j++) {
			remain[j] = arr[j] % i;
		}

		for (int j = 0; j < N - 1; j++) {
			if (remain[j] == remain[j + 1])
				count++;

			if (count == N - 1)
				cout << i << ' ';
		}

		count = 0;
	}
}


// 시간 초과가 난 풀이
// 최대공약수의 약수를 구할 때, i가 너무 많이 돌아 시간 초과가 발생한다.

#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int num1, int num2);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int arr[100];
	int share[100];
	int gcd;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	gcd = arr[1] - arr[0];

	for (int i = 2; i < N; i++)
		gcd = GCD(gcd, arr[i] - arr[i - 1]);

	for (int i = 2; i <= gcd; i++) {
		if (!(gcd % i))
			cout << i << ' ';
	}
}

inline int GCD(int num1, int num2)
{
	if (!num2)
		return num1;
	return GCD(num2, num1 % num2);
}



// 맞은 풀이

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int num1, int num2);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int arr[100];
	int share[100];
	int gcd;
	vector <int> v;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	gcd = arr[1] - arr[0];

	for (int i = 2; i < N; i++)
		gcd = GCD(gcd, arr[i] - arr[i - 1]);

	// 16 = 4 * 4. 4까지만 검사한다. 2같은 경우, 16으로 나눠떨어지므로, 당연히 그 짝인 8도 해당되도록 한다.
	for (int i = 2; i * i <= gcd; i++) {
		if (!(gcd % i)) {
			v.push_back(i);
			v.push_back(gcd / i);
		}
	}

	v.push_back(gcd);

	sort(v.begin(), v.end());
	// 중복된 원소를 제거한다.
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
}

inline int GCD(int num1, int num2)
{
	if (!num2)
		return num1;
	return GCD(num2, num1 % num2);
}