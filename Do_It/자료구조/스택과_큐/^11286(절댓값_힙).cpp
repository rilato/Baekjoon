// 우선순위 큐는 top 메서드를 호출했을 때, 우선 순위가 가장 높은 것을 꺼내는 구조
// 우선순위 큐의 선언은 priority_queue <int, vector <int>, compare> pq;
// 또는 priority_queue <pair<int, int>, vector <pair <int, int>>, compare> pq;

// pq의 주요 연산
// pq.push(num);
// pq.pop();
// pq.top();    -> 우선순위가 가장 높은 트리의 루트에 해당하는 값 호출
// pq.empty();

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 우선순위 큐의 compare함수는 구조체를 사용한다.
// compare를 구현하기 위한 핵심은, 두 자료를 비교했을 때 swap를 해줄 것인지 말 것인지 (return true이면 swap, false이면 swap X) 결정하는 것이다.
struct compare {
    // a는 부모 노드이고 b는 현재 노드이다.
    bool operator()(int a, int b) {
        int first_abs = abs(a);
        int second_abs = abs(b);

        if (first_abs == second_abs) {
            // 자식(b)가 부모(a)보다 작다면, true이므로 swap을 진행함.
            // 이를 반복하다 보면 조상 노드는 가장 작은 원소가 차지할 것이다.
            return a > b;    // 음수 (작은 수) 우선 정렬

            // 자식(b)가 부모(a)보다 크다면, true이므로 swap을 진행함.
            // 이를 반복하다 보면 조상 노드는 가장 큰 원소가 차지하게 된다.
            // return a < b;
        }
        else {
            // 자식(second_abs)가 부모(first_abs)보다 작다면, true이므로 swap을 진행함.
            // 이를 반복하다 보면 조상 노드는 가장 작은 원소가 차지할 것.
            return first_abs > second_abs;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    // 우선순위 큐 선언 방식 : <자료형, 구현체, 비교 함수명>
    priority_queue <int, vector <int>, compare> pq;  // 첫 번째에는 절대값 수, 두 번째에는 원래의 진짜 수를 저장

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;

        if (num == 0) {
            if (pq.empty())
                cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }

        else {
            pq.push(num);
        }
    }

    return 0;
}