#include <iostream>
#include <deque>

using namespace std;

int main(void) {

    ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	int n, m; cin>>n>>m;
	int left, right, cnt=0;

	for(int i=0; i<n; i++) dq.push_back(i+1);

	while(m--) {
        int num; cin>>num;
        for(int i=0; i<dq.size(); i++) {
            if(dq[i]==num) {
                left=i;
                right=dq.size()-i;
                break;
            }
        }

        if(left<right) {
            while(1) {
                if(dq.front()==num) break;
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        }
        else {
            cnt++;
            while(1) {
                if(dq.back()==num) break;
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_back();
        }
	}

	cout<<cnt;

	return 0;
}

// 연산을 단순화할 수 있는 방법을 모색해보기.