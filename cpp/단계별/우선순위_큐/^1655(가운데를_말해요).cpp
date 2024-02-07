// https://regularmember.tistory.com/142

// 1. 최소 힙의 값들은 모두 최대 힙보다 크도록하고
// 2. 최대 힙의 크기가 최소 힙의 크기보다 1 크거나 같도록 유지하며 값을 넣는다.
// 3. 값을 넣어준 후 최대 힙과 최소 힙의 top 값을 비교해서 최소 힙의 top보다 최대 힙의 top이 더 크다면 값을 교환해준다.
// 그러면 최대 힙의 top값이 중간값이 된다.


// 시간 초과가 난 풀이

// 값이 계속 들어올 때마다 중간값을 출력해주어야 하기 때문에 매번 정렬을 해서 가운데 값을 출력해주면 시간 초과가 발생한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num, midIndex;
    int k = -1;
    vector <int> v;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        v.push_back(num);
        ++k;
        stable_sort(v.begin(), v.end());
        midIndex = k / 2;
        cout << v[midIndex] << '\n';
    }
}


// 맞은 풀이

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num;
    priority_queue <int> maxHeap;
    priority_queue <int, vector<int>, greater<int>> minHeap;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;

        if (maxHeap.empty() || maxHeap.size() == minHeap.size())
            maxHeap.push(num);
        else
            minHeap.push(num);

        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int mintop = minHeap.top();
            int maxtop = maxHeap.top();
            minHeap.pop();
            maxHeap.pop();
            minHeap.push(maxtop);
            maxHeap.push(mintop);
        }

        cout << maxHeap.top() << '\n';
    }
}