// test case�� �¾�����, ��Ÿ�� ������ �߻��ߴ�.

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
//		// ���ڿ��� ����ִ��� Ȯ���ϴ� �Լ� : .empty()
//		if (myWord[word.size()][j].empty())
//			myWord[word.size()][j] = word;
//
//		// ���ڿ��� ������� ������ �ݺ����� ������.
//		else {
//			while (!myWord[word.size()][j].empty()) {
//				// ���̰� N�� ���ڰ� �� �� ���Դ��� count�� �����ش�.
//				++count;
//
//				// �Է��� �ܾ ���̰� N�� ���� ��, ���� ���� �´� ��ġ�� �����ϸ� break�Ѵ�.
//				if (myWord[word.size()][j] >= word)
//					break;
//				++j;
//			}
//
//			// �ܾ �̹� �ִٸ�, �� �ܾ�� �������� �ʴ´�.
//			if (myWord[word.size()][j] == word)
//				continue;
//
//			// �ش� �ܾ ���ڸ��� �ֱ� ����, ������ �ִ� �ܾ �ڷ� �ϳ��� �̷��.
//			else {
//				for (int J = jMax; J >= j; J--)
//					myWord[word.size()][J + 1] = myWord[word.size()][J];
//
//				myWord[word.size()][j] = word;
//			}
//		}
//
//		// print�� �� for���� �ּ������� ������ ���� iMax�� jMax�� ���Ѵ�.
//		// iMax�� ���� �ܾ� �����̰�, jMax�� ���� ���� ���� �ܾ��� ���� Ƚ����.
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



 //sort(����, ��, compare�Լ�)
 //compare�Լ��� bool type����, ������ ���� �������� �Ѵ�.
 //compare�Լ��� return���� return a < b; ������ ��Ÿ����.
 //> �� ������������, < �� ������������ ���ĵȴ�.

 //vector�� �ߺ��� �����ϱ� ���ؼ�, erase�� unique�Լ��� ����Ѵ�.
 //vector <int> v; ���� v�� ������ ���ҵ��� �������� ����� �ʹٸ�

 //1. ������ �Ѵ� : sort
 //2. '���ӵ�' �ߺ� ���Ҹ� ���� �� �κ�(������ ��)���� ���������� : unique
 //3. �ߺ��� ���ҵ��� ���ִ� ���� �޺κ��� �����Ѵ� : erase

 //unique�Լ��� ��ȯ ���� vector "������ ���� ù��° ��ġ"�� �ǹǷ� �ٷ� erase �Լ� �ȿ� ��ø�ؼ� ����� �� �ִ�!!


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

	//iterator�� ������� �ʰ� �׳� int i = 0�� ����ϸ�, ������ ���� ���� �� ������ ���� ��ġ�� ����� ã�� ���� �ʴ�.
	//���� segmentation fault�� �� �� �ִ�.
	//���� vector���� erase�� ����� �Ŀ��� iterator�� ����Ͽ� ���� ��Ÿ����.
	for (auto iter = wordVector.begin(); iter != wordVector.end(); iter++) {
		cout << *iter << '\n';
	}
}

bool compare(string a, string b) {
	// �� �ܾ��� ����� ������ ������ ���� ���� ������
	if (a.size() == b.size())
		return a < b;

	// �� �ܾ��� ����� �ٸ��� ����� ���� ���� ������
	return a.size() < b.size();
}