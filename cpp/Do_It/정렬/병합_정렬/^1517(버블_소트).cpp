// 문제 이름은 버블 소트이지만, 시간 초과가 발생하므로 머지 소트를 이용한다.
// 머지 소트에서, 쪼개진 부분을 병합하는 과정에 버블 소트의 swap이 포함되어있다.
// 해당 아이디어를 통해 버블 소트의 swap 횟수를 계산한다.

#include <iostream>
#include <vector>

using namespace std;

long long sorted[500001];
vector<long long> arr;
long long ans = 0;

void merge_sort(int left, int right);
void merge(int left, int mid, int right);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;

		arr.push_back(num);
	}

	merge_sort(0, n - 1);

	cout << ans;

	return 0;
}

void merge_sort(int left, int right) {
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	merge_sort(left, mid);
	merge_sort(mid + 1, right);
	merge(left, mid, right);
}

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			// 뒤쪽 데이터 값이 작아 선택되는 경우 결과값 업데이트
			ans += j - k;
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int x = j; x <= right; x++) {
			sorted[k] = arr[x];
			k++;
		}
	}
	else {
		for (int x = i; x <= mid; x++) {
			sorted[k] = arr[x];
			k++;
		}
	}
	for (int x = left; x <= right; x++) {
		arr[x] = sorted[x];
	}
}