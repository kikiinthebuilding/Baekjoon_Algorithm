#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, score, max=0;
    int nums[4];
    cin>>N;
    while(N--) {
        score=0;
        cin>>nums[0]>>nums[1]>>nums[2]>>nums[3];
        sort(nums, nums+4);
        if(nums[0]==nums[3]) score=50000+nums[3]*5000;
        else if(nums[0]==nums[2]) score=10000+nums[2]*1000;
        else if(nums[1]==nums[3]) score=10000+nums[3]*1000;
        else if(nums[0]==nums[1] && nums[2]==nums[3]) score=2000+nums[1]*500+nums[3]*500;
        else if(nums[0]==nums[1]) score=1000+nums[1]*100;
        else if(nums[1]==nums[2]) score=1000+nums[2]*100;
        else if(nums[2]==nums[3]) score=1000+nums[3]*100;
        else score=nums[3]*100;
        
        if(score>max) max=score;
    }
    cout<<max<<endl;
}