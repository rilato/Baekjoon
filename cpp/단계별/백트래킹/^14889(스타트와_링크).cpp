// �����е� �ʱ� ����

#include <iostream>
#include <cmath>

using namespace std;

int N;
int minimum = 100;
int arr[20][20];
bool visited[20];

void bt(int cnt, int cur);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	// ī��Ʈ�� 0���� ����, ���ڴ� -1���� ����
	bt(0, -1);

	cout << minimum;
}

// cnt�� ī��Ʈ ��, �� ���̸� ��Ÿ����.
// cur�� ���� ����Ǿ��ִ� �ε����� ���� �ǹ��Ѵ�.
void bt(int cnt, int cur) {
	// ī��Ʈ ���� ������ ������ �Ǿ��� �� �ɷ�ġ�� �� ��� �� ���� ���
	if (cnt == N / 2) {
		int start = 0;
		int link = 0;

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (visited[i] && visited[j]) {
					start += arr[i][j] + arr[j][i];
				}
				if (!visited[i] && !visited[j]) {
					link += arr[i][j] + arr[j][i];
				}
			}
		}

		minimum = min(minimum, abs(start - link));
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i] && i > cur) {
			visited[i] = true;
			bt(cnt + 1, i);
			// ����
			visited[i] = false;
		}
	}
}