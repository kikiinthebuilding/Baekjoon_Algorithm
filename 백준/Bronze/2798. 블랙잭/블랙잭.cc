#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M; cin>>N>>M;
    vector<int> nums;
    
    for(int i=0, temp; i<N; i++) {
        cin>>temp;
        nums.push_back(temp);
    }

    int min=M, sum;
    for(int i=0; i<N-2; i++) {
        for(int j=i+1; j<N-1; j++) {
            for(int k=j+1; k<N; k++) {
                sum = nums[i]+nums[j]+nums[k];
                if(min>M-sum && sum<=M) min=M-sum;
            }
        }
    }
    cout<<M-min<<endl;
    return 0;
}