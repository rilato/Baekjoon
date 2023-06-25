// https://deeepbreathing.tistory.com/28
// pair의 사용법을 익힌다.
// 대소 비교 및 sort에 의한 정렬에서 : 첫번째 인자 기준, 첫번째가 같으면 두번째인자로 판단

#include <iostream>
#include <queue>

using namespace std;

// second에 실제값이 들어가는 이유는 greater<pair<int,int>>비교 부분에서 오름차순으로 정렬하는데,
// 이때 first -> second순으로 비교하여 정렬해주기 때문이다.
// 그니까 만약 1,-1이 입력된 후 0이 입력되었다면
// 절댓값은 각각 1,1이 될 것이고, 둘의 값이 같으므로 second순으로 비교하게 되어 -1이 먼저 출력될 것이다.

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void priorityQueue(int num);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        priorityQueue(num);
    }
}

void priorityQueue(int num) {
    if (!num) {
        if (pq.empty())
            cout << '0' << '\n';

        else {
            cout << pq.top().second << '\n';
            pq.pop();
        }
    }

    if (num)
        pq.push({ abs(num), num });
}