#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string k;
    int n;
    
    cin >> n;

  	// ignore()함수는 앞선 7번째 줄의 n의 입력버퍼가 11번에 문자열을 입력하는 부분의 입력으로 들어가는 경우를 방지하기 위해 사용.
	  // ignore()함수는 입력한 이후 입력버퍼를 지워주는 역할을 함.
    cin.ignore();
    
    while(n--) {
        getline(cin,k);
        
        if ('a' <= k[0] && k[0] <= 'z')
            k[0] -= 32;
        
        cout << k << '\n';
    }
}
