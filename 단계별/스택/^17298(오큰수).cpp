// while문 안의 for문보다
// for문 안의 while문이 더 빠른 듯하다.

//n과 배열을 입력받는다.
//배열을 뒤에서부터 검사한다.스택이 비어있지 않고 스택의 top이 배열의 수보다 작거나 같다면 스택을 pop해준다.이 과정은 while문을 통해 스택이 empty되거나 스택의 top이 배열의 수보다 클때까지 반복된다.
//스택이 empty라면 결과 배열에 - 1을 넣어준다.
//스택에 배열의 수를 push해준다.
//이 과정을 배열의 마지막 인덱스에서 첫번째 인덱스까지 반복한다.

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
	// 배열의 맨 마지막 값부터 검사한다.
	for (int i = n - 1; i >= 0; i--) {
		// 스택의 맨 위 값은 오큰수를 의미한다. 
		// 스택이 비어있지 않고, 스택의 맨 위 값이 배열의 해당 값보다 작거나 같으면 스택의 값을 pop한다.
		while (!st.empty() && st.top() <= arr[i])
			st.pop();

		if (st.empty())
			result[i] = -1;

		else
			result[i] = st.top();

		// for문을 거치면서, 배열의 맨 뒤 값부터 차례대로 스택에 넣는다.
		st.push(arr[i]);
	}

	// result[i] = st.top();를 통해서 result는 스택의 top을 거치게 되었고, 스택은 가장 나중에 들어온 값을 먼저 출력하므로, int i = 0부터 i++을 하면 나중에 들어온 값부터 출력된다.
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


// 시간 초과가 난 풀이
// 이중 for문을 사용하면, 시간 복잡도가 O(N^2)이므로 시간 초과가 발생한다.

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



// 마찬가지로 시간초과가 발생한다

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