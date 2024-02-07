// 앞서 사용했던 방식대로 아래의 코드를 작성하면 메모리 초과가 발생한다.

//#include <iostream>
//#include <algorithm>

//using namespace std;

//int main() {
	//int input;

	//cin >> input;

	//int* arr = new int[input];

	//for (int i = 0; i < input; i++) {
		//cin >> arr[i];
	//}

	//sort(arr, arr + input);

	//for (int i = 0; i < input; i++)
		//cout << arr[i] << '\n';

	//delete[] arr;
//}



// 입력받은 수를 전부 다 입력받아서 저장하게 되면 제한된 8MB의 메모리를 초과해버린다.
// 숫자를 카운트 해두었다가 표준출력으로 출력만 해주는 방식을 사용해야한다.

// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);를 통해 동기화를 끊어주어야 속도가 향상된다.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num;
	int arr[10001] = { 0, };

	cin >> input;

	// 사용자에게 input만큼 num값을 입력받는데, num 위치에 해당하는 배열 값을 1씩 증가시킨다.
	// 이렇게 되면 해당 배열의 값과 인덱스 값을 통해 어떠한 수가 얼마나 입력되었는지 알 수 있다.
	for (int i = 0; i < input; i++) {
		cin >> num;
		arr[num]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (arr[i]) {
			for (int j = 0; j < arr[i]; j++)
				cout << i << '\n';
		}
	}
}