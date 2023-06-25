// 우선순위 큐 STL을 확인한다.
// https://zoosso.tistory.com/993

#include <iostream>
#include <queue>

using namespace std;

priority_queue <int> pq;

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
            cout << pq.top() << '\n';
            pq.pop();
        }
    }

    if (num)
        pq.push(num);
}