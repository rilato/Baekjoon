// �׸��� �˰��� �� �����ٸ��� �̿��Ѵ�.
// https://cocoon1787.tistory.com/147
// �����е� �ʱ� Ȯ��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, time;
	int count = 1;

	cin >> N;

	vector <pair <int, int>> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i].second >> v[i].first;

	// ȸ�ǰ� ������ �ð��� �������� ����
	sort(v.begin(), v.end());

	// ���ʷ� ȸ�ǰ� ������ �ð��� time�� ����
	time = v[0].first;

	for (int i = 1; i < N; i++) {
		// ȸ�� ���� �ð��� ȸ�ǰ� ������ �ð��� ���ų� �ʴ� ���
		if (time <= v[i].second) {
			// �ش� ȸ�ǽð��� ���� time���� ������ְ� 1ȸ ����
			time = v[i].first;
			count++;
		}
	}

	cout << count;
}