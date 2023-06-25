// vector의 insert의 사용법을 익힌다.

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;

	cin >> n;

	vector <int> arr(n);

	for (int i = 1; i <= n; i++) {
		cin >> tmp;

		arr.insert(arr.begin() + tmp, i);	// arr.begin() + tmp는 새로운 원소가 추가될 위치(index), i는 삽입할 원소의 값
	}

	// 거꾸로 출력
	for (int i = n - 1; i >= 0; i--)
		cout << arr[i] << ' ';
}