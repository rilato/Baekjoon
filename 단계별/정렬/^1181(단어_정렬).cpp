// test case는 맞았으나, 런타임 에러가 발생했다.

#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int input;
//	int iMax = 0, jMax = 0;
//	string word;
//
//	cin >> input;
//
//	string** myWord = new string* [50];
//
//	for (int i = 0; i < 50; i++) {
//		myWord[i] = new string[input];
//	}
//
//	for (int i = 0; i < input; i++) {
//		int j = 0;
//		int count = 0;
//
//		cin >> word;
//
//		// 문자열이 비어있는지 확인하는 함수 : .empty()
//		if (myWord[word.size()][j].empty())
//			myWord[word.size()][j] = word;
//
//		// 문자열이 비어있을 때까지 반복문을 돌린다.
//		else {
//			while (!myWord[word.size()][j].empty()) {
//				// 길이가 N인 문자가 몇 번 나왔는지 count가 세어준다.
//				++count;
//
//				// 입력한 단어가 길이가 N인 문자 중, 사전 순에 맞는 위치에 도달하면 break한다.
//				if (myWord[word.size()][j] >= word)
//					break;
//				++j;
//			}
//
//			// 단어가 이미 있다면, 그 단어는 포함하지 않는다.
//			if (myWord[word.size()][j] == word)
//				continue;
//
//			// 해당 단어를 제자리에 넣기 위해, 기존에 있는 단어를 뒤로 하나씩 미룬다.
//			else {
//				for (int J = jMax; J >= j; J--)
//					myWord[word.size()][J + 1] = myWord[word.size()][J];
//
//				myWord[word.size()][j] = word;
//			}
//		}
//
//		// print할 때 for문을 최소한으로 돌리기 위해 iMax와 jMax를 구한다.
//		// iMax는 최장 단어 길이이고, jMax는 가장 많이 나온 단어의 등장 횟수다.
//		if (word.size() > iMax)
//			iMax = word.size();
//		if (count > jMax)
//			jMax = count;
//	}
//
//	for (int i = 0; i <= iMax; i++)
//		for (int j = 0; j <= jMax; j++)
//			if (!myWord[i][j].empty())
//				cout << myWord[i][j] << '\n';
//
//	for (int i = 0; i < 50; i++) {
//		delete[] myWord[i];
//	}
//
//	delete[] myWord;
//}



 //sort(시작, 끝, compare함수)
 //compare함수는 bool type으로, 본인이 직접 만들어줘야 한다.
 //compare함수의 return값은 return a < b; 등으로 나타낸다.
 //> 은 내림차순으로, < 은 오름차순으로 정렬된다.

 //vector의 중복을 제거하기 위해서, erase와 unique함수를 사용한다.
 //vector <int> v; 에서 v를 유일한 원소들의 집합으로 만들고 싶다면

 //1. 정렬을 한다 : sort
 //2. '연속된' 중복 원소를 제일 뒷 부분(쓰레기 값)으로 보내버린다 : unique
 //3. 중복된 원소들이 모여있는 제일 뒷부분을 삭제한다 : erase

 //unique함수는 반환 값이 vector "쓰레기 값의 첫번째 위치"가 되므로 바로 erase 함수 안에 중첩해서 사용할 수 있다!!


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string, string);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input;
	string word;
	vector <string> wordVector;

	cin >> input;

	for (int i = 0; i < input; i++) {
		cin >> word;
		wordVector.push_back(word);
	}

	sort(wordVector.begin(), wordVector.end(), compare);
	wordVector.erase(unique(wordVector.begin(), wordVector.end()), wordVector.end());

	//iterator를 사용하지 않고 그냥 int i = 0을 사용하면, 쓰레기 값을 지운 후 마지막 값의 위치가 어딘지 찾기 쉽지 않다.
	//따라서 segmentation fault가 뜰 수 있다.
	//따라서 vector에서 erase를 사용한 후에는 iterator를 사용하여 값을 나타낸다.
	for (auto iter = wordVector.begin(); iter != wordVector.end(); iter++) {
		cout << *iter << '\n';
	}
}

bool compare(string a, string b) {
	// 두 단어의 사이즈가 같으면 사전순 빠른 것이 앞으로
	if (a.size() == b.size())
		return a < b;

	// 두 단어의 사이즈가 다르면 사이즈가 작은 것이 앞으로
	return a.size() < b.size();
}