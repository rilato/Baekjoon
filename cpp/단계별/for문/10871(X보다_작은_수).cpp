// 배열
#include <iostream>

using namespace std;

int main()
{
	int N, X, A;
	int arr[10000];

	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		cin >> A;
		arr[i] = A;
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] < X)
			cout << arr[i] << " ";
	}
}


// 동적 할당
#include <iostream>

using namespace std;

int main()
{
	// 입출력 속도를 높이기 위한 코드
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, X;
	cin >> N;
	cin >> X;
	int* A = new int[N];		// 배열 동적 할당

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++)
		if (A[i] < X)
			cout << A[i] << ' ';
	delete[]A;			// new를 사용했다면 꼭 필요한 작업
}