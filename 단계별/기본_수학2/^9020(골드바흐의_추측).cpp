// 4 이상의 짝수는 모두 두 소수의 합으로 이루어진다. ex) 8 = 3 + 5 / 10 = 5 + 5 or 3 + 7
// 이를 골드바흐의 추측이라고 한다.

// for문을 최대한 적게 사용해야 한다.
// 골드바흐의 수를 보면, 짝수를 반으로 쪼갠 후, 앞의 수는 점점 작게, 뒤의 수는 점점 크게하여 두 소수의 합을 원래 수로 만들면 된다.
// 소수 + 소수 = 짝수에서 소수 = 짝수 - 소수이다.
// 따라서 for문을 돌릴 때 num/2부터 시작하며, 앞의 수를 i로 잡고, i를 기준으로 하나씩 줄여나간다.

#include <iostream>
#include <cmath>

using namespace std;

bool isPrimeNumber(int num);

int main() {
	int input, evenNum;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> evenNum;

		for (int i = evenNum / 2; i > 1; i--) {       // 수를 반으로 쪼개어 앞의 수를 i, 뒤의 수를 j로 놓는다.
			int j = evenNum - i;

			if (isPrimeNumber(i) && isPrimeNumber(j)) {
				cout << i << ' ' << j << '\n';
				break;
			}
		}
	}
}

bool isPrimeNumber(int num) {
	int root = sqrt(num);

	for (int i = 2; i <= root; i++) {
		if (!(num % i))	// 나머지가 0이면 합성수
			return 0;
	}

	return 1;
}


// 시간 초과가 난 풀이 -> 동적할당을 통해 배열을 받고, 일일히 초기화해주는 작업에서 시간이 오래 걸린 듯하다.

#include <iostream>
#include <cmath>

using namespace std;

void goldbach(int num);

int main() {
	int input, evenNum;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> evenNum;
		goldbach(evenNum);
	}
}

void goldbach(int num) {
	int* arr = new int[num];
	int j = 0;

	for (int i = 0; i < num; i++)
		arr[i] = 1;

	for (int i = 2; i <= num - 1; i++) {			// 소수인 것은 1로, 소수가 것은 0으로 초기화
		for (int j = 2; j <= (int)sqrt(num); j++) {
			if (!(i % j))
				arr[i] = 0;
		}
	}

	for (int i = num / 2; i > 1; i--) {
		if (arr[i] == 1) {
			j = num - i;
			if (arr[j] == 1) {
				cout << i << ' ' << j << '\n';
				break;
			}
		}
	}

	delete[] arr;
}