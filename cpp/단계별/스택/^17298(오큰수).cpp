// while�� ���� for������
// for�� ���� while���� �� ���� ���ϴ�.

//n�� �迭�� �Է¹޴´�.
//�迭�� �ڿ������� �˻��Ѵ�.������ ������� �ʰ� ������ top�� �迭�� ������ �۰ų� ���ٸ� ������ pop���ش�.�� ������ while���� ���� ������ empty�ǰų� ������ top�� �迭�� ������ Ŭ������ �ݺ��ȴ�.
//������ empty��� ��� �迭�� - 1�� �־��ش�.
//���ÿ� �迭�� ���� push���ش�.
//�� ������ �迭�� ������ �ε������� ù��° �ε������� �ݺ��Ѵ�.

#include <iostream>
#include <stack>
#define MAX 1000001
using namespace std;

int n;
int arr[MAX];
int result[MAX];
stack<int> st;

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void Solution() {
	// �迭�� �� ������ ������ �˻��Ѵ�.
	for (int i = n - 1; i >= 0; i--) {
		// ������ �� �� ���� ��ū���� �ǹ��Ѵ�. 
		// ������ ������� �ʰ�, ������ �� �� ���� �迭�� �ش� ������ �۰ų� ������ ������ ���� pop�Ѵ�.
		while (!st.empty() && st.top() <= arr[i])
			st.pop();

		if (st.empty())
			result[i] = -1;

		else
			result[i] = st.top();

		// for���� ��ġ�鼭, �迭�� �� �� ������ ���ʴ�� ���ÿ� �ִ´�.
		st.push(arr[i]);
	}

	// result[i] = st.top();�� ���ؼ� result�� ������ top�� ��ġ�� �Ǿ���, ������ ���� ���߿� ���� ���� ���� ����ϹǷ�, int i = 0���� i++�� �ϸ� ���߿� ���� ������ ��µȴ�.
	for (int i = 0; i < n; i++)
		cout << result[i] << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solution();

	return 0;
}


// �ð� �ʰ��� �� Ǯ��
// ���� for���� ����ϸ�, �ð� ���⵵�� O(N^2)�̹Ƿ� �ð� �ʰ��� �߻��Ѵ�.

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num, max = 0;
	vector <int> v;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < input; i++) {
		max = v[i];

		for (int j = i; j < input; j++) {
			if (v[j] > max) {
				max = v[j];
				break;
			}
		}

		if (max == v[i])
			cout << -1 << ' ';
		else
			cout << max << ' ';
	}
}



// ���������� �ð��ʰ��� �߻��Ѵ�

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num, max = 0;
	vector <int> arr, ans;
	stack <int> s;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> num;
		arr.push_back(num);
		s.push(num);
	}

	int index = input - 1;
	int Index = index;

	while (1) {
		if (s.empty())
			break;

		max = s.top();

		for (int i = Index; i < input; i++) {
			if (arr[i] > max) {
				max = arr[i];
				ans.push_back(max);
				break;
			}
		}

		if (max == arr[Index])
			ans.push_back(-1);

		s.pop();
		--Index;
	}

	for (int i = input - 1; i >= 0; i--)
		cout << ans[i] << ' ';
}