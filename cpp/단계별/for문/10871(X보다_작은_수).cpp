// �迭
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


// ���� �Ҵ�
#include <iostream>

using namespace std;

int main()
{
	// ����� �ӵ��� ���̱� ���� �ڵ�
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, X;
	cin >> N;
	cin >> X;
	int* A = new int[N];		// �迭 ���� �Ҵ�

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++)
		if (A[i] < X)
			cout << A[i] << ' ';
	delete[]A;			// new�� ����ߴٸ� �� �ʿ��� �۾�
}